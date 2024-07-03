# This layer shall be common for all RPi variants.

PV_pn-packagegroup-vendor-layer = "1.0.0"
PR_pn-packagegroup-vendor-layer = "r0"

# Refer Comcast Jira RDK-50570: PACKAGE_ARCH_pn should have MLPREFIX for successful build.

# HAL Components
require conf/include/vendor_pkg_versions_halif_impl.inc

#Linux kernel components

PV_pn-linux-libc-headers = "5.10.52"
PR_pn-linux-libc-headers = "r0"
PACKAGE_ARCH_pn-linux-libc-headers = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_linux-libc-headers = "5.10.%"

PV_pn-android-raspberrypi = "5.10.82"
PR_pn-android-raspberrypi = "r0"
PACKAGE_ARCH_pn-lib32-android-raspberrypi = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_android-raspberrypi = "5.10.%"

PV_pn-packagegroup-kernel-modules-raspberrypi4 = "5.10.82"
PR_pn-packagegroup-kernel-modules-raspberrypi4 = "r0"
PACKAGE_ARCH_pn-packagegroup-kernel-modules-raspberrypi4 = "${VENDOR_LAYER_EXTENSION}"

PV_pn-linux-firmware-rpidistro = "1.0.0"
PR_pn-linux-firmware-rpidistro = "r0"
PACKAGE_ARCH_pn-linux-firmware-rpidistro = "${VENDOR_LAYER_EXTENSION}"

#platfrom components

PV_pn-bluez-firmware-rpidistro = "1.0.0"
PR_pn-bluez-firmware-rpidistro = "r0"
PACKAGE_ARCH_pn-lib32-bluez-firmware-rpidistro = "${VENDOR_LAYER_EXTENSION}"

PV_pn-userland = "20200624"
PR_pn-userland = "r0"
PACKAGE_ARCH_pn-lib32-userland = "${VENDOR_LAYER_EXTENSION}"

PV_pn-pi-bluetooth = "0.1.12"
PR_pn-pi-bluetooth = "r0"
PACKAGE_ARCH_pn-lib32-pi-bluetooth = "${VENDOR_LAYER_EXTENSION}"

PV_pn-udev-rules-rpi = "1.0"
PR_pn-udev-rules-rpi = "r0"
PACKAGE_ARCH_pn-udev-rules-rpi = "${VENDOR_LAYER_EXTENSION}"

PV_pn-sysint-soc = "1.0.0"
PR_pn-sysint-soc = "r0"
PACKAGE_ARCH_pn-sysint-soc = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-sysint-soc = "e24c053d203164befd7ae000abb5e7657d54dc0b"

#OSS Components

PV_pn-libepoxy = "1.5.4"
PR_pn-libepoxy = "r0"
PACKAGE_ARCH_pn-lib32-libepoxy = "${VENDOR_LAYER_EXTENSION}"

PV_pn-make-mod-scripts = "1.0"
PR_pn-make-mod-scripts = "r0"
PACKAGE_ARCH_pn-make-mod-scripts = "${VENDOR_LAYER_EXTENSION}"

PV_pn-cairo = "1.14.6"
PR_pn-cairo = "r1"
PACKAGE_ARCH_pn-lib32-cairo = "${VENDOR_LAYER_EXTENSION}"

PV_pn-libdrm = "2.4.100"
PR_pn-libdrm = "r0"
PACKAGE_ARCH_pn-lib32-libdrm = "${VENDOR_LAYER_EXTENSION}"

PV_pn-mesa = "20.0.2"
PR_pn-mesa = "r0"
PACKAGE_ARCH_pn-lib32-mesa = "${VENDOR_LAYER_EXTENSION}"

PV_pn-librsvg = "2.40.21"
PR_pn-librsvg = "r0"
PACKAGE_ARCH_pn-lib32-librsvg = "${VENDOR_LAYER_EXTENSION}"

PV_pn-mpg123 = "1.25.13"
PR_pn-mpg123 = "r0"
PACKAGE_ARCH_pn-lib32-mpg123 = "${VENDOR_LAYER_EXTENSION}"

PV_pn-pango = "1.44.7"
PR_pn-pango = "r0"
PACKAGE_ARCH_pn-lib32-pango = "${VENDOR_LAYER_EXTENSION}"

PV_pn-pulseaudio = "13.0"
PR_pn-pulseaudio = "r0"
PACKAGE_ARCH_pn-lib32-pulseaudio = "${VENDOR_LAYER_EXTENSION}"

PV_pn-libmms = "0.6.4"
PR_pn-libmms = "r0"
PACKAGE_ARCH_pn-lib32-libmms = "${VENDOR_LAYER_EXTENSION}"

PV_pn-alsa-plugins = "1.2.1"
PR_pn-alsa-plugins = "r0"
PACKAGE_ARCH_pn-lib32-alsa-plugins = "${VENDOR_LAYER_EXTENSION}"

#Gstreamer components

GST_VERSION = "1.18.5"
GST_REVISION = "r0"

PV_pn-gstreamer1.0 = "${GST_VERSION}"
PR_pn-gstreamer1.0 = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0 = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0 ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-base = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-base = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-base = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-base ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-base-meta = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-base-meta = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-base-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-base-meta ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-libav = "${GST_VERSION}"
PR_pn-gstreamer1.0-libav = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-libav = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-libav ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-good = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-good = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-good = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-good ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-good-meta = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-good-meta = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-good-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-good-meta ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-bad = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-bad = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-bad = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-bad ?= "${GST_VERSION}"

PV_pn-gstreamer1.0-plugins-bad-meta = "${GST_VERSION}"
PR_pn-gstreamer1.0-plugins-bad-meta = "${GST_REVISION}"
PACKAGE_ARCH_pn-lib32-gstreamer1.0-plugins-bad-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-bad-meta ?= "${GST_VERSION}"

# Westeros components
WESTEROS_VERSION = "1.0.0"
WESTEROS_REVISION = "r0"
# Tip of westeros master as of Mar 7, 2024
WESTEROS_SRCREV = "04c096cb3df0bc0797f5b6bc568e1d11b62dcb5b"

PV_pn-westeros-simplebuffer = "${WESTEROS_VERSION}"
PR_pn-westeros-simplebuffer = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-westeros-simplebuffer = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-westeros-simplebuffer = "${WESTEROS_SRCREV}"

PV_pn-westeros-simpleshell = "${WESTEROS_VERSION}"
PR_pn-westeros-simpleshell = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-westeros-simpleshell = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-westeros-simpleshell = "${WESTEROS_SRCREV}"

PV_pn-westeros-soc-drm = "${WESTEROS_VERSION}"
PR_pn-westeros-soc-drm = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-westeros-soc-drm = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-westeros-soc-drm = "${WESTEROS_SRCREV}"

PV_pn-westeros = "${WESTEROS_VERSION}"
PR_pn-westeros = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-westeros = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-westeros = "${WESTEROS_SRCREV}"

PV_pn-essos = "${WESTEROS_VERSION}"
PR_pn-essos = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-essos = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-essos = "${WESTEROS_SRCREV}"

PV_pn-westeros-sink = "${WESTEROS_VERSION}"
PR_pn-westeros-sink = "${WESTEROS_REVISION}"
PACKAGE_ARCH_pn-lib32-westeros-sink = "${VENDOR_LAYER_EXTENSION}"
SRCREV_pn-westeros-sink = "${WESTEROS_SRCREV}"

