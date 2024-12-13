# remove 'enable_ripple' until the build error fixes
DISTRO_FEATURES:remove = ' enable_ripple'

# Temporary until RDKEMW-746 is fixed
DISTRO_FEATURES:remove = ' subtec'
DISTRO_FEATURES:remove = ' texttrack'
