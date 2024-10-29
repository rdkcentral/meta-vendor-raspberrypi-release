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

# To fix RDE-331 
SRCREV:pn-bluetooth-mgr = "d56af28b6166ffa3f7bb838b44987f84e47e6642"
SRCREV:pn-bluetooth-core = "226da0d9a57cdd659401b53d7de803ef1027df04"

# Temp solution for RDK-53835
SRCREV:pn-telemetry = "7a80452173d1809153fd86f75f3e95d1611b230e"

# Fix for RDK-53836 firebolt-native-sdk
SRCREV:pn-tts = "17a14cbadef9df5ce7f3e685e8333ecf6ae6b949"

# Temp fix for RDK-54180, remove once the ticket is resolved
SRCREV_rdkfw = "611668991cd454578740848a4ab34729b7454f7e"
