# Fix the build error; related to: https://github.com/rdk-e/meta-image-support/pull/136
PROJECT_BRANCH ?= "${RDKE_GITHUB_BRANCH}"

VENDOR_LAYER_VERSION = "4.4.3"

VENDOR_LAYER_EXTENSION = "${MACHINE}-vendor"
VENDOR_IPK_SERVER_PATH = "${RDK_ARTIFACTS_BASE_URL}/opkg/${MACHINE}/ipks/${VENDOR_LAYER_EXTENSION}/${VENDOR_LAYER_VERSION}"

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

# RDKVREFPLT-5430: dsmgr requires wpeframework-rdkshell; remove the cyclic dependency.
update_wpeframework_rdkshell_service() {
    THUNDER_RDKSHELL_SERVICE_FILE="${IMAGE_ROOTFS}/lib/systemd/system/wpeframework-rdkshell.service"
    DSMGR_SERVICE_FILE="${IMAGE_ROOTFS}/lib/systemd/system/dsmgr.service"

    if [ -f "$THUNDER_RDKSHELL_SERVICE_FILE" ] && [ -f "$DSMGR_SERVICE_FILE" ]; then
        # Remove dsmgr.service from wpeframework-rdkshell.service
        sed -i '/^Requires=.*dsmgr.service/ s/dsmgr.service//' "$THUNDER_RDKSHELL_SERVICE_FILE"
        sed -i '/^After=.*dsmgr.service/ s/dsmgr.service//' "$THUNDER_RDKSHELL_SERVICE_FILE"
        echo "Removed dsmgr.service from ${THUNDER_RDKSHELL_SERVICE_FILE}..."

        # Remove wpeframework-rdkshell.service from dsmgr.service
        sed -i '/^Requires=.*wpeframework-rdkshell.service/ s/wpeframework-rdkshell.service//' "$DSMGR_SERVICE_FILE"
        sed -i '/^After=.*wpeframework-rdkshell.service/ s/wpeframework-rdkshell.service//' "$DSMGR_SERVICE_FILE"
        echo "Removed wpeframework-rdkshell.service from ${DSMGR_SERVICE_FILE}..."
    fi
}
ROOTFS_POSTPROCESS_COMMAND += "update_wpeframework_rdkshell_service; "
