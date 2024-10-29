SUMMARY = "Custom package group for vendor layer"
PACKAGE_ARCH = "${VENDOR_LAYER_EXTENSION}"

LICENSE = "MIT"

inherit packagegroup

PV = "1.0.0"
PR = "r0"

# SSH Key shall be generated in RW section - /opt.
update_dropbearkey_to_rw_path() {
   if [ -f "${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service" ]; then
        sed -i 's/\/etc\dropbear/\/opt\dropbear/g' ${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service
   fi
}
ROOTFS_POSTPROCESS_COMMAND += "update_dropbearkey_to_rw_path; "
