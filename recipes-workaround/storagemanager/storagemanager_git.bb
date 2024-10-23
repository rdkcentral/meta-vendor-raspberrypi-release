# ============================================================================
# RDK MANAGEMENT, LLC CONFIDENTIAL AND PROPRIETARY
# ============================================================================
# This file (and its contents) are the intellectual property of RDK Management, LLC.
# It may not be used, copied, distributed or otherwise  disclosed in whole or in
# part without the express written permission of RDK Management, LLC.
# ============================================================================
# Copyright (c) 2016 RDK Management, LLC. All rights reserved.
# ============================================================================
#
SUMMARY = "Storage Manager recipe"
SECTION = "console/utils"

LICENSE = "RDK"
LIC_FILES_CHKSUM = "file://LICENSES.TXT;md5=dec68053378991f05886652485036010"

PACKAGE_ARCH = "${MIDDLEWARE_ARCH}"

PV ?= "1.0.0"
PR ?= "r0"
STRMGR_TSB_DURATION = "25"
SRC_URI = "${RDKE_GITHUB_ROOT}/storagemanager;${RDKE_GITHUB_SRC_URI_SUFFIX}"
S = "${WORKDIR}/git"

EXTRA_OECONF = "--disable-static --disable-silent-rules --enable-diskcheck --enable-yocto"
EXTRA_OECONF:append_rpi = " --enable-tsb-sign-no-check"
PACKAGECONFIG += "refactored"
PACKAGECONFIG += "${@bb.utils.contains('DISTRO_FEATURES', 'storage_hdd','smartsupport', '',d)}"
PACKAGECONFIG += "${@bb.utils.contains('DISTRO_FEATURES', 'storage_sdc','sdcardsupport', '',d)}"
PACKAGECONFIG += " sdcardsupport"

PACKAGECONFIG[refactored]   = "--enable-refactored-mgr,--disable-refactored-mgr"
PACKAGECONFIG[smartsupport] = "--enable-smartsupport,--disable-smartsupport"
PACKAGECONFIG[sdcardsupport] = "--enable-sdc,--disable-sdc"
PACKAGECONFIG[breakpad] = "--enable-breakpad,,breakpad,"

DEPENDS       += "${@bb.utils.contains('DISTRO_FEATURES', 'storage_hdd','xfsprogs', '',d)}"
DEPENDS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', ' safec', " ", d)}"

INCLUDEDIR = " \
        -I${PKG_CONFIG_SYSROOT_DIR}/usr/include/glib-2.0 \
        -I${PKG_CONFIG_SYSROOT_DIR}/${libdir}/glib-2.0/include \
	-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/rdk/iarmbus \
        -I${PKG_CONFIG_SYSROOT_DIR}/usr/include/wdmp-c \
	-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/directfb \
	-I${PKG_CONFIG_SYSROOT_DIR}/usr/include/rdk/iarmmgrs-hal \
"

CXXFLAGS += "${INCLUDEDIR} -DENABLE_SD_NOTIFY -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE "
CFLAGS += "${INCLUDEDIR} -DENABLE_SD_NOTIFY -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE "
LDFLAGS += "-lsystemd -lsecure_wrapper -lglib-2.0 -lrfcapi"

DEPENDS += "iarmmgrs dbus glib-2.0 systemd libsyswrapper breakpad safec-common-wrapper wdmp-c rfc"

inherit autotools systemd pkgconfig coverity syslog-ng-config-gen breakpad-wrapper breakpad-logmapper
SYSLOG-NG_FILTER = "storagemgrmain"
SYSLOG-NG_SERVICE_storagemgrmain = "storagemgrmain.service"
SYSLOG-NG_DESTINATION_storagemgrmain = "storagemgr.log"
SYSLOG-NG_LOGRATE_storagemgrmain = "medium"

# generating minidumps
PACKAGECONFIG:append = " breakpad"
BREAKPAD_BIN:append = " storageMgrMain"
# Breakpad processname and logfile mapping
BREAKPAD_LOGMAPPER_PROCLIST = "storageMgrMain"
BREAKPAD_LOGMAPPER_LOGLIST = "storagemgr.log"

CXXFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec',  ' `pkg-config --cflags libsafec`', '-fPIC', d)}"

LDFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', ' `pkg-config --libs libsafec`', '', d)}"
CXXFLAGS:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'safec', '', ' -DSAFEC_DUMMY_API', d)}"

do_install:append() {
        install -d ${D}${sysconfdir}
        install -d ${D}${sysconfdir}/rfcdefaults
        install -d ${D}${systemd_unitdir}/system

        install -m 0644 ${S}/conf/storageMgr.conf ${D}${sysconfdir}
        install -m 0644 ${S}/conf/storagemanager.ini ${D}${sysconfdir}/rfcdefaults
        install -m 0644 ${S}/storagemgrmain.service ${D}${systemd_unitdir}/system
        install -D -m 0644 ${S}/disk-check.conf ${D}${systemd_unitdir}/system/storagemgrmain.service.d/storagemgrmain.conf
}

SYSTEMD_SERVICE:${PN} += "storagemgrmain.service"
FILES:${PN} += "${bindir}/*"
FILES:${PN} += "${sysconfdir}/storageMgr.conf"
FILES:${PN} += "${sysconfdir}/rfcdefaults/storagemanager.ini"
FILES:${PN} += "${systemd_unitdir}/system/storagemgrmain.service"
FILES:${PN} += "${systemd_unitdir}/system/storagemgrmain.service.d/storagemgrmain.conf"
