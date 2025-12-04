PROJECT_BRANCH ?= "${RDKE_GITHUB_BRANCH}"

VENDOR_LAYER_VERSION = "4.9.0"
VENDOR_EXTENSION = "-vendor"

VENDOR_LAYER_EXTENSION = "${MACHINE}${VENDOR_EXTENSION}"
VENDOR_IPK_PATH ?= "${VENDOR_LAYER_EXTENSION}/${VENDOR_LAYER_VERSION}/ipks/"
VENDOR_IPK_SERVER_PATH ?= "${RDK_ARTIFACTS_BASE_URL}/${VENDOR_IPK_PATH}"

PACKAGE_EXTRA_ARCHS:append = " ${VENDOR_LAYER_EXTENSION}"

# To set the remote feeds
IPK_FEED_URIS += " \
                ${VENDOR_LAYER_EXTENSION}##${VENDOR_IPK_SERVER_PATH} "

OSS_LAYER_VERSION = "4.10.0"
VENDOR_OSS = "${@get_oss_arch(d)}${VENDOR_EXTENSION}"

PACKAGE_EXTRA_ARCHS:append = "${@ '' if '${VENDOR_OSS}' == '${OSS_LAYER_ARCH}' else ' ${VENDOR_OSS}'}"
OPKG_ARCH_PRIORITY:${VENDOR_OSS} = "310"
OSS_MACHINE = "${@get_oss_machine(d)}"

VENDOR_OSS_IPK_PATH ?= "${VENDOR_OSS}/${OSS_LAYER_VERSION}/ipks/"
VENDOR_OSS_IPK_SERVER_PATH ?= "${RDK_ARTIFACTS_BASE_URL}/${VENDOR_OSS_IPK_PATH}"

IPK_FEED_URIS += " \
                ${VENDOR_OSS}##${VENDOR_OSS_IPK_SERVER_PATH} "

# SSH Key shall be generated in RW section - /opt.
update_dropbearkey_to_rw_path() {
    if [ -f "${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service" ]; then
        sed -i '/\/var/d; /\/var\/lib/d; s/\/etc\/dropbear/\/opt\/dropbear/g; s/\/var\/lib\/dropbear/\/opt\/dropbear/g' ${IMAGE_ROOTFS}/lib/systemd/system/dropbearkey.service
    else
        echo "No dropbearkey.service file detected at '${IMAGE_ROOTFS}', SSH may not work."
    fi
}
ROOTFS_POSTPROCESS_COMMAND += "update_dropbearkey_to_rw_path; "
