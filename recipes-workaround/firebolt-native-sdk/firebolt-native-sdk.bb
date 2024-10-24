# Remove when RDK-53836 is resolved

SUMMARY = "Native SDK"
DESCRIPTION = "Recipe for building Native SDK"

LICENSE = "CLOSED"

inherit cmake

SRC_URI = "${RDKE_GITHUB_ROOT}/firebolt-entos-runtime-apis;${RDKE_GITHUB_SRC_URI_SUFFIX}"

SRCREV:pn-firebolt-native-sdk = "7f43a06f325e15678d41ef5f0921368eccaf9d57"

S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MIDDLEWARE_ARCH}"

DEPENDS = "wpeframework wpeframework-tools-native"

do_install() {
     echo "The D is (${D})"
     echo "The B is (${B})"
     ls -l ${B}/..

     install -d ${D}/${libdir}
     cp -R ${B}/src/*.so* ${D}/${libdir}

     install -d ${D}${includedir}
     mkdir -p ${D}${includedir}/Firebolt
     mkdir -p ${D}${includedir}/Firebolt/common
     install -m 0644 ${B}/../git/include/*.h ${D}${includedir}/Firebolt
     install -m 0644 ${B}/../git/include/common/*.h ${D}${includedir}/Firebolt/common
}
