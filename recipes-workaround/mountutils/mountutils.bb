#To do - Remove when RDK-53835 is resolved
#
# ============================================================================
# COMCAST C O N F I D E N T I A L AND PROPRIETARY
# ============================================================================
# This file and its contents are the intellectual property of Comcast.  It may
# not be used, copied, distributed or otherwise  disclosed in whole or in part
# without the express written permission of Comcast.
# ============================================================================
# Copyright (c) 2018 Comcast. All rights reserved.
# ============================================================================
#
SUMMARY = "mount-utils-generic"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MIDDLEWARE_ARCH}"
SRC_URI = "${RDKE_GITHUB_ROOT}/mount-utils-cpc;${RDKE_GITHUB_SRC_URI_SUFFIX};name=generic"

PV ?= "1.0.1"
PR ?= "r0"

SRCREV_FORMAT = "generic"
SRCREV:pn-mountutils = "05c1e8431bc219e66d1de7f5b0ceddd5dd7047ef"

S = "${WORKDIR}/git"
DEPENDS = " safec-common-wrapper libsyswrapper"
DEPENDS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', ' safec', " ", d)}"

CFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec',  ' `pkg-config --cflags libsafec`', '-fPIC', d)}"
CFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', '', ' -DSAFEC_DUMMY_API', d)}"

LDFLAGS:append = " -lsecure_wrapper"
LDFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', ' `pkg-config --libs libsafec`', '', d)}"
CFLAGS:append = " -fPIC"

inherit pkgconfig autotools coverity

do_install() {
           install -d ${D}/${bindir}
           install -d ${D}${libdir}
           install -d ${D}${includedir}
           install -m 0755 ${S}/RdkConfigApi/include/rdkconfig.h ${D}${includedir}/
           install -m 0644 RdkConfigApi/src/librdkconfig.a ${D}${libdir}
	install -m 0755 RdkConfigApi/src/GetConfigFile ${D}/${bindir}/
           install -m 0755 ${S}/GetServiceUrl ${D}/${bindir}/
}

FILES:${PN} += "${bindir}/*"

