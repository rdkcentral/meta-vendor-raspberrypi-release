# enable distro with RDKVREFPLT-3798 
DISTRO_FEATURES:remove = ' enable_rialto'

# Fix for RDK-53836 firebolt-native-sdk
SRCREV:pn-tts = "c2e8a894023dc2709a3b63b169803dce0653d1ea"

# Temp fix for RDK-54180, remove once the ticket is resolved
SRCREV_rdkfw = "611668991cd454578740848a4ab34729b7454f7e"
