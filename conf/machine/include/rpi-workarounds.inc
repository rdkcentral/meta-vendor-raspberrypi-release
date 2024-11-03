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
SRCREV:pn-tts = "e49fff3e8e3d1d78982c628453f8132f29198c98"

# Temp fix for RDK-54180, remove once the ticket is resolved
SRCREV_rdkfw = "611668991cd454578740848a4ab34729b7454f7e"
