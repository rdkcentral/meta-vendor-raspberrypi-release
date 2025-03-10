COBALT_PERSISTENTPATHPOSTFIX = "Cobalt/Cobalt"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# TODO: PREMIUMAPP-3208: remove when changes are available from middleware.
SRC_URI += "file://0001-Plugin-change-to-remove-IDictionary-interface.patch;patchdir=${WORKDIR}/git"
SRC_URI += "file://0001-Remove-Internet-from-precondition.patch;patchdir=${WORKDIR}/git"
