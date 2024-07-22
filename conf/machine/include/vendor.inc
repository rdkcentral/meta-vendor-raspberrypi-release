# To support layered ipk generation
include conf/include/rdke-vendor-bbmask.inc
# Fix the build error; related to: https://github.com/rdk-e/meta-image-support/pull/136
PROJECT_BRANCH ?= "${RDKE_GITHUB_BRANCH}"

VENDOR_LAYER_EXTENSION = "${MACHINE}-vendor"

VENDOR_IPK_SERVER_PATH = "${RDK_ARTIFACTS_BASE_URL}/opkg/${MACHINE}/ipks/${VENDOR_LAYER_EXTENSION}/1.2.1"

PACKAGE_EXTRA_ARCHS_append = " ${VENDOR_LAYER_EXTENSION}"

# To set the remote feeds
IPK_FEED_URIS += " \
                ${VENDOR_LAYER_EXTENSION}##${VENDOR_IPK_SERVER_PATH} "

require conf/include/vendor_pkg_versions.inc

