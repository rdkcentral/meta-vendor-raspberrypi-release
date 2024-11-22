# enable distro with RDKVREFPLT-3798 
DISTRO_FEATURES:remove = ' enable_rialto'

# TODO: Temp fix for RDK-54180 RDKE-413, remove once the ticket is resolved
SRCREV_rdkfw = "2333e72e70551ec0fccf10188f7e4c3a860d9f0c"

# TODO: Temp fix for RDKE-429 & RDKE-468; until iptables gets refactored
SRCREV:pn-sysint = "dd2385dc839c687f2428e1d21589de9ddc830e6b"
