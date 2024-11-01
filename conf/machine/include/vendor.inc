# Fix the build error; related to: https://github.com/rdk-e/meta-image-support/pull/136
PROJECT_BRANCH ?= "${RDKE_GITHUB_BRANCH}"

VENDOR_LAYER_EXTENSION = "${MACHINE}-vendor"

VENDOR_IPK_SERVER_PATH = "${RDK_ARTIFACTS_BASE_URL}/opkg/${MACHINE}/ipks/${VENDOR_LAYER_EXTENSION}/develop/RDKVREFPLT-3658"

PACKAGE_EXTRA_ARCHS:append = " ${VENDOR_LAYER_EXTENSION}"

# To set the remote feeds
IPK_FEED_URIS += " \
                ${VENDOR_LAYER_EXTENSION}##${VENDOR_IPK_SERVER_PATH} "

