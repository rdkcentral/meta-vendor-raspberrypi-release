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

# Remove when systimemgr is enabled for RDKM
DISTRO_FEATURES:remove = "systimemgr"

# enable distro with RDKVREFPLT-3798 
DISTRO_FEATURES:remove = ' enable_rialto'

# To do: Remove when RDK-54034 is resolved
LICENSE_FLAGS_ACCEPTED:append  = " commercial_${MLPREFIX}fdk-aac "
