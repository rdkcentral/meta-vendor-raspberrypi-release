SUMMARY = "No Operation Recipe for secapi adapter version 2.0"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = "file://${MANIFEST_PATH_PLATFORM}/LICENSE;md5=5bfad6e034e497ee148eec56e175c6e8"

PROVIDES = "virtual/rdk-gstreamer-utils-platform virtual/vendor-rdk-gstreamer-utils-platform"
RPROVIDES:${PN} = "virtual/rdk-gstreamer-utils-platform virtual/vendor-rdk-gstreamer-utils-platform"

ALLOW_EMPTY:${PN} = "1"

do_configure[noexec] = "1"
do_compile[noexec] = "1"
do_install[noexec] = "1"

FILES_${PN} = ""
