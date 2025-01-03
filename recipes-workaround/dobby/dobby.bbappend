FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
# Remove once RDKEMW-421 is fixed and release
SRC_URI += " file://dobby.json"

do_install:append(){
    install -d ${D}${sysconfdir}

    #Copy the dobby config file to /etc/
    install -m 0644 ${S}/../dobby.json ${D}${sysconfdir}/dobby.json
}

FILES:${PN} += "${sysconfdir}/dobby.json"
