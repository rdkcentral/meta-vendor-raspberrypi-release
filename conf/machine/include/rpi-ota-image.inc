# The RDK OTA image for RPi - creation logic
#
# The function do_create_ota_image_wic requires uncompressed 'wic' image created matching IMAGE_BASENAME.
# It copies ${DEPLOY_DIR_IMAGE}/${IMAGE_BASENAME}*.wic as ${OTA_IMAGE_NAME} and
# deletes the PARTITIONS 3 & 4 which are added by 'wic/sdimage-raspberrypi.wks' as /root2 and /persist.
# Then it truncates ${OTA_IMAGE_NAME} to save space by adding only /boot and /root1 in the OTA package.

OTA_IMAGE_NAME ?= "${IMAGE_NAME}-ota.wic"

python do_create_ota_image_wic() {
    import os
    import subprocess
    import tarfile
    from bb import note, error, fatal

    deploy_dir_image = d.getVar('DEPLOY_DIR_IMAGE')
    image_basename = d.getVar('IMAGE_NAME')

    note("DEPLOY_DIR_IMAGE: {}".format(deploy_dir_image))
    note("IMAGE_NAME: {}".format(image_basename))

    if not deploy_dir_image:
        fatal("DEPLOY_DIR_IMAGE is not set or is empty.")
    if not image_basename:
        fatal("IMAGE_NAME is not set or is empty.")

    ota_image_name = d.getVar('OTA_IMAGE_NAME')
    ota_tar_gz_name = ota_image_name + ".tar.gz"

    note("OTA_IMAGE_NAME: {}".format(ota_image_name))
    note("OTA_TAR_GZ_NAME: {}".format(ota_tar_gz_name))

    # Find the generated WIC image
    wic_image = None
    for file in os.listdir(deploy_dir_image):
        note("Checking file: {}".format(file))
        if file.startswith(image_basename) and file.endswith('.wic'):
            wic_image = os.path.join(deploy_dir_image, file)
            break

    if not wic_image:
        error("Not able to find {}*.wic for OTA image creation.".format(image_basename))
        return 1

    # Create a copy of the uncompressed WIC image
    ota_wic_image = os.path.join(deploy_dir_image, ota_image_name)
    note("Using {} for creating {}...".format(wic_image, ota_wic_image))
    subprocess.run(['cp', wic_image, ota_wic_image], check=True)

    # Remove /root2 and /opt partitions
    size_before = os.path.getsize(ota_wic_image)
    note("Size of {} before deleting partitions: {} bytes".format(ota_wic_image, size_before))

    partitions = subprocess.check_output(['parted', '-s', ota_wic_image, 'print']).decode('utf-8')
    for line in partitions.splitlines():
        if line.startswith(' '):
            parts = line.split()
            part_num = parts[0]
            part_name = parts[-1]
            if part_name in ["root2", "persist"] or part_num in ["3", "4"]:
                note("Deleting partition {} with label {}...".format(part_num, part_name))
                subprocess.run(['sfdisk', '--delete', ota_wic_image, part_num], check=True)

    # Calculate the end sector of the last remaining partition
    end_sector_output = subprocess.check_output(['parted', '-s', ota_wic_image, 'print']).decode('utf-8')
    end_sector_str = [line.split()[2] for line in end_sector_output.splitlines() if ' 2 ' in line][0]

    # Convert end_sector_str to sectors
    if end_sector_str.endswith('KB'):
        end_sector = int(float(end_sector_str[:-2]) * 1024 / 512)
    elif end_sector_str.endswith('MB'):
        end_sector = int(float(end_sector_str[:-2]) * 1024 * 1024 / 512)
    elif end_sector_str.endswith('GB'):
        end_sector = int(float(end_sector_str[:-2]) * 1024 * 1024 * 1024 / 512)
    else:
        end_sector = int(end_sector_str.replace('s', ''))

    note("Calculated end_sector is {}.".format(end_sector))

    # Truncate the OTA_WIC_IMAGE to the end of the last remaining partition using Python
    with open(ota_wic_image, 'r+b') as f:
        f.truncate(end_sector * 512)

    size_after = os.path.getsize(ota_wic_image)
    note("Size of {} after deleting partitions and truncating: {} bytes".format(ota_wic_image, size_after))

    ota_tar_gz_path = os.path.join(deploy_dir_image, ota_tar_gz_name)
    with tarfile.open(ota_tar_gz_path, "w:gz") as tar:
        tar.add(ota_wic_image, arcname=os.path.basename(ota_wic_image))

    note("Compressed OTA image created successfully: {}".format(ota_tar_gz_path))

    # Remove the OTA WIC file to save space keeping only the compressed one.
    os.remove(ota_wic_image)
    note("Removed intermediate OTA WIC file to save space: {}".format(ota_wic_image))
}

# Append the steps to do_image_wic
do_image_wic[postfuncs] += " do_create_ota_image_wic"

