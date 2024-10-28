#From meta-rdk-oss-reference
BBMASK += " meta-rdk-oss-reference/recipes-support/cryptsetup/cryptsetup_1.7.2.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-support/lvm2/lvm2_2.02.138.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-mac/Apparmor/apparmor_%.bbappend"
BBMASK += " meta-rdk-oss-reference/recipes-kernel/linux-libc-headers/linux-libc-headers_4.9.bb"
#From meta-openembedded
BBMASK += " meta-openembedded/meta-multimedia/recipes-multimedia/tinyalsa/tinyalsa.bb"
BBMASK += " meta-openembedded/meta-oe/recipes-devtools/breakpad/breakpad_svn.bb"

# Remove when systimemgr is enabled for RDKM
DISTRO_FEATURES:remove = "systimemgr"

# enable distro with RDKVREFPLT-3798 
DISTRO_FEATURES:remove = ' enable_rialto'

# To do: Remove when RDK-54034 is resolved
LICENSE_FLAGS_ACCEPTED:append  = " commercial_${MLPREFIX}fdk-aac "

# To fix RDE-331 
SRCREV:pn-bluetooth-mgr = "04e090730275276e26741564b4bab7a799ef2d4c"
# Temp solution for RDK-53835
SRCREV:pn-telemetry = "7a80452173d1809153fd86f75f3e95d1611b230e"

# Fix for RDK-53836 firebolt-native-sdk
SRCREV:pn-tts = "7e7c799d0900317f8c1679c7e5132952bc8d4b51"
