OTA_IMAGE_NAME = "${MACHINE_IMAGE_NAME}-${IMAGE_BASENAME}-ota-image.wic"

do_create_ota_image_wic() {
    bbnote "Arun: from do_create_ota_image_wic..."

    # Find the generated WIC image
    WIC_IMAGE=$(ls ${DEPLOY_DIR_IMAGE}/${IMAGE_BASENAME}-*.wic | head -n 1)
    if [ -z "${WIC_IMAGE}" ]; then
        bberror "Not able to find ${IMAGE_BASENAME}-*.wic for OTA image creation."
        return 1
    fi

    # Create a copy of the uncompressed WIC image
    OTA_WIC_IMAGE=${DEPLOY_DIR_IMAGE}/${OTA_IMAGE_NAME}
    bbnote "Using ${WIC_IMAGE} for creating ${OTA_WIC_IMAGE}..."
    cp ${WIC_IMAGE} ${OTA_WIC_IMAGE}

    # Remove /root2 and /opt partitions
    SIZE_BEFORE=$(stat -c%s "${OTA_WIC_IMAGE}")
    bbnote "Size of ${OTA_WIC_IMAGE} before deleting partitions: ${SIZE_BEFORE} bytes"

    PARTITIONS=$(parted -s ${OTA_WIC_IMAGE} print | awk '/^ [0-9]/ {print $1, $NF}')
    echo "${PARTITIONS}" | while read -r PART_NUM PART_NAME; do
        bbnote "PART_NUM = ${PART_NUM} and PART_NAME = '${PART_NAME}'."
        if [ "${PART_NAME}" = "root2" ] || [ "${PART_NAME}" = "persist" ]; then
            bbnote "Deleting partition ${PART_NUM} with label ${PART_NAME}..."
            sfdisk --delete ${OTA_WIC_IMAGE} ${PART_NUM}
        else
            bbnote "No match found for partition ${PART_NUM} with label ${PART_NAME}."
        fi
    done

    SIZE_AFTER=$(stat -c%s "${OTA_WIC_IMAGE}")
    bbnote "Size of ${OTA_WIC_IMAGE} after deleting partitions: ${SIZE_AFTER} bytes"

    bbnote "OTA image created successfully: ${OTA_WIC_IMAGE}"
}

addtask do_create_ota_image_wic after do_image_complete before do_populate_lic_deploy
