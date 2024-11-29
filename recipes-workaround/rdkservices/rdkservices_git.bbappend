PACKAGECONFIG:remove = " xcast opencdmi_wv opencdmi_pr4"

# Remove when RDK-54147 is resolved
EXTRA_OECMAKE:remove = " -DPLUGIN_RDKSHELL_READ_MAC_ON_STARTUP=ON"
