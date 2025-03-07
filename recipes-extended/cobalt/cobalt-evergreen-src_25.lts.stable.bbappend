# RPi specifc change
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# Workaround for REFPLTV-2693
SRC_URI += "file://0001-wayland-changes-cobalt24.patch"
