#From meta-rdk-oss-reference
BBMASK += " meta-rdk-oss-reference/recipes-support/cryptsetup/cryptsetup_1.7.2.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-support/lvm2/lvm2_2.02.138.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-mac/Apparmor/apparmor_%.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-kernel/linux-libc-headers/linux-libc-headers_4.9.bb"
#From meta-openembedded
BBMASK += " meta-openembedded/meta-multimedia/recipes-multimedia/tinyalsa/tinyalsa.bb"
BBMASK += " meta-openembedded/meta-oe/recipes-devtools/breakpad/breakpad_svn.bb"

#From meta-rdk-halif-headers
# FIXME: unmask as integration progresses
BBMASK += " meta-rdk-halif-headers/recipes-rdk-halif-headers/tvsettings"

#workarounds
BBMASK += " meta-rdk/recipes-qt/*"

DISTRO_FEATURES:remove = "systimemgr"
DISTRO_FEATURES:remove = ' enable_rialto'
LICENSE_FLAGS_ACCEPTED:append  = " commercial_${MLPREFIX}fdk-aac "

# Add source rev for rdkfwupgrader
PV:pn-rdkfwupgrader = "1.3.6"
PR:pn-rdkfwupgrader = "r0"
PACKAGE_ARCH:pn-rdkfwupgrader = "${MIDDLEWARE_ARCH}"
SRCREV_rdkfw = "ad96e6712c5bd2a13f3a4aedeff3abd482a2e7ac"
SRCREV:pn-storagemanager = "f5d34a7a8ae13d94fea0f7046976e22f0d11c97d"
