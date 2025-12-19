PROJECT_BRANCH ?= "${RDKE_GITHUB_BRANCH}"

VENDOR_LAYER_VERSION = "4.9.1"

VENDOR_LAYER_EXTENSION = "${MACHINE}-vendor"
VENDOR_IPK_SERVER_PATH ?= "${RDK_ARTIFACTS_BASE_URL}/${MACHINE}-release/${VENDOR_LAYER_VERSION}/${MACHINE}/ipks/debug"

PACKAGE_EXTRA_ARCHS:append = " ${VENDOR_LAYER_EXTENSION}"

# To set the remote feeds
IPK_FEED_URIS += " \
                ${VENDOR_LAYER_EXTENSION}##${VENDOR_IPK_SERVER_PATH} "

# SSH Key shall be generated in RW section - /opt.
update_dropbearkey_to_rw_path() {
    if [ -f "${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service" ]; then
        sed -i '/\/var/d; /\/var\/lib/d; s/\/etc\/dropbear/\/opt\/dropbear/g; s/\/var\/lib\/dropbear/\/opt\/dropbear/g' ${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service
    else
        echo "No dropbearkey.service file detected at '${IMAGE_ROOTFS}', SSH may not work."
    fi
}
ROOTFS_POSTPROCESS_COMMAND += "update_dropbearkey_to_rw_path; "
