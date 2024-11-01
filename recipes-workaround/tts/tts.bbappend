# Remove when RDK-53836 is resolved
DEPENDS:remove = "firebolt-native-sdk"
EXTRA_OECMAKE:remove = "${@bb.utils.contains('DISTRO_FEATURES', 'TTS_Preload', ' -DTTS_DEFAULT_BACKEND=comrpc', ' -DTTS_DEFAULT_BACKEND=firebolt', d)}"
