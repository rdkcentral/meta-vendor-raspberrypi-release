# This layer shall be common for all RPi variants.

PV:pn-packagegroup-vendor-layer = "1.2.5"
PR:pn-packagegroup-vendor-layer = "r0"

# Refer Comcast Jira RDK-50570: PACKAGE_ARCH_pn should have MLPREFIX for successful build.

# HAL Components
require conf/include/vendor_pkg_versions_halif_impl.inc

#Linux kernel components

PR:pn-linux-libc-headers = "r0"
PACKAGE_ARCH:pn-linux-libc-headers = "${VENDOR_LAYER_EXTENSION}"

PV:pn-android-raspberrypi = "5.15.92"
PR:pn-android-raspberrypi = "r0"
PACKAGE_ARCH:pn-android-raspberrypi = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_android-raspberrypi = "5.15.%"

PV:pn-packagegroup-kernel-modules-raspberrypi4 = "5.15.92"
PR:pn-packagegroup-kernel-modules-raspberrypi4 = "r0"
PACKAGE_ARCH:pn-packagegroup-kernel-modules-raspberrypi4 = "${VENDOR_LAYER_EXTENSION}"

PV:pn-linux-firmware-rpidistro = "1.0.0"
PR:pn-linux-firmware-rpidistro = "r0"
PACKAGE_ARCH:pn-linux-firmware-rpidistro = "${VENDOR_LAYER_EXTENSION}"

#platfrom components

PV:pn-bluez-firmware-rpidistro = "1.0.0"
PR:pn-bluez-firmware-rpidistro = "r0"
PACKAGE_ARCH:pn-bluez-firmware-rpidistro = "${VENDOR_LAYER_EXTENSION}"

PV:pn-userland = "20220323"
PR:pn-userland = "r0"
PACKAGE_ARCH:pn-userland = "${VENDOR_LAYER_EXTENSION}"

PV:pn-pi-bluetooth = "0.1.17"
PR:pn-pi-bluetooth = "r0"
PACKAGE_ARCH:pn-pi-bluetooth = "${VENDOR_LAYER_EXTENSION}"

PV:pn-udev-rules-rpi = "1.0"
PR:pn-udev-rules-rpi = "r0"
PACKAGE_ARCH:pn-udev-rules-rpi = "${VENDOR_LAYER_EXTENSION}"

PV:pn-sysint-soc = "1.0.2"
PR:pn-sysint-soc = "r0"
PACKAGE_ARCH:pn-sysint-soc = "${VENDOR_LAYER_EXTENSION}"

#OSS Components

PV:pn-libepoxy = "1.5.9"
PR:pn-libepoxy = "r0"
PACKAGE_ARCH:pn-libepoxy = "${VENDOR_LAYER_EXTENSION}"

PV:pn-make-mod-scripts = "1.0"
PR:pn-make-mod-scripts = "r0"
PACKAGE_ARCH:pn-make-mod-scripts = "${VENDOR_LAYER_EXTENSION}"

PV:pn-cairo = "1.16.6"
PR:pn-cairo = "r1"
PACKAGE_ARCH:pn-cairo = "${VENDOR_LAYER_EXTENSION}"

PV:pn-libdrm = "2.4.110"
PR:pn-libdrm = "r0"
PACKAGE_ARCH:pn-libdrm = "${VENDOR_LAYER_EXTENSION}"

PV:pn-mesa = "22.0.3"
PR:pn-mesa = "r0"
PACKAGE_ARCH:pn-mesa = "${VENDOR_LAYER_EXTENSION}"

PV:pn-librsvg = "2.40.21"
PR:pn-librsvg = "r0"
PACKAGE_ARCH:pn-librsvg = "${VENDOR_LAYER_EXTENSION}"

PV:pn-mpg123 = "1.29.13"
PR:pn-mpg123 = "r0"
PACKAGE_ARCH:pn-mpg123 = "${VENDOR_LAYER_EXTENSION}"

PV:pn-pango = "1.44.7"
PR:pn-pango = "r0"
PACKAGE_ARCH:pn-pango = "${VENDOR_LAYER_EXTENSION}"

PV:pn-pulseaudio = "15.0"
PR:pn-pulseaudio = "r0"
PACKAGE_ARCH:pn-pulseaudio = "${VENDOR_LAYER_EXTENSION}"

PV:pn-libmms = "0.6.4"
PR:pn-libmms = "r0"
PACKAGE_ARCH:pn-libmms = "${VENDOR_LAYER_EXTENSION}"

PV:pn-alsa-plugins = "1.2.6"
PR:pn-alsa-plugins = "r0"
PACKAGE_ARCH:pn-alsa-plugins = "${VENDOR_LAYER_EXTENSION}"

PV:pn-python3-pycairo = "1.21.0"
PR:pn-python3-pycairo = "r1"
PACKAGE_ARCH:pn-python3-pycairo = "${VENDOR_LAYER_EXTENSION}"

PV:pn-python3-pygobject = "3.42.0"
PR:pn-python3-pygobject = "r1"
PACKAGE_ARCH:pn-python3-pygobject = "${VENDOR_LAYER_EXTENSION}"

#Gstreamer components

GST_VERSION = "1.18.5"
GST_REVISION = "r0"

PV:pn-gstreamer1.0 = "${GST_VERSION}"
PR:pn-gstreamer1.0 = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0 = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0 ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-base = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-base ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-base-meta = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-meta = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-base-meta ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-libav = "${GST_VERSION}"
PR:pn-gstreamer1.0-libav = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-libav = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-libav ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-good = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-good ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-good-meta = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-meta = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-good-meta ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-bad = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-bad ?= "${GST_VERSION}"

PV:pn-gstreamer1.0-plugins-bad-meta = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-meta = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-meta = "${VENDOR_LAYER_EXTENSION}"
PREFERRED_VERSION_gstreamer1.0-plugins-bad-meta ?= "${GST_VERSION}"

#Newly added
PV:pn-gstreamer1.0-rtsp-server = "${GST_VERSION}"
PR:pn-gstreamer1.0-rtsp-server = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-rtsp-server = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-omx = "${GST_VERSION}"
PR:pn-gstreamer1.0-omx = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-omx = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-meta-base = "${GST_VERSION}"
PR:pn-gstreamer1.0-meta-base = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-meta-base = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-playback = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-playback = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-playback = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-wavparse = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-wavparse = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-wavparse = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-audiofx = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-audiofx = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-audiofx = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-isomp4 = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-isomp4 = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-isomp4 = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-audioparsers = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-audioparsers = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-audioparsers = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-soup = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-soup = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-soup = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-gio = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-gio = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-gio = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-videoconvert  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-videoconvert  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-videoconvert = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-videoscale  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-videoscale  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-videoscale = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-volume  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-volume  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-volume = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-typefindfunctions  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-typefindfunctions  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-typefindfunctions = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-autodetect  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-autodetect  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-autodetect = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-avi  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-avi  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-avi = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-deinterlace  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-deinterlace  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-deinterlace = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-interleave  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-interleave  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-interleave = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-bad-dash  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-dash  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-dash = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-bad-mpegtsdemux  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-mpegtsdemux  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-mpegtsdemux = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-bad-smoothstreaming  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-smoothstreaming  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-smoothstreaming = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-bad-videoparsersbad  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-videoparsersbad  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-videoparsersbad = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-bad-opusparse  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-bad-opusparse  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-bad-opusparse = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-good-matroska  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-good-matroska  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-good-matroska = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-app  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-app  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-app = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-audioconvert  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-audioconvert  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-audioconvert = "${VENDOR_LAYER_EXTENSION}"

PV:pn-gstreamer1.0-plugins-base-audioresample  = "${GST_VERSION}"
PR:pn-gstreamer1.0-plugins-base-audioresample  = "${GST_REVISION}"
PACKAGE_ARCH:pn-gstreamer1.0-plugins-base-audioresample = "${VENDOR_LAYER_EXTENSION}"

# Westeros components
WESTEROS_VERSION = "1.0.0"
WESTEROS_REVISION = "r0"
# Tip of westeros master as of Mar 7, 2024
WESTEROS_SRCREV = "04c096cb3df0bc0797f5b6bc568e1d11b62dcb5b"

PV:pn-westeros-simplebuffer = "${WESTEROS_VERSION}"
PR:pn-westeros-simplebuffer = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-westeros-simplebuffer = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-westeros-simplebuffer = "${WESTEROS_SRCREV}"

PV:pn-westeros-simpleshell = "${WESTEROS_VERSION}"
PR:pn-westeros-simpleshell = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-westeros-simpleshell = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-westeros-simpleshell = "${WESTEROS_SRCREV}"

PV:pn-westeros-soc-drm = "${WESTEROS_VERSION}"
PR:pn-westeros-soc-drm = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-westeros-soc-drm = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-westeros-soc-drm = "${WESTEROS_SRCREV}"

PV:pn-westeros = "${WESTEROS_VERSION}"
PR:pn-westeros = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-westeros = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-westeros = "${WESTEROS_SRCREV}"

PV:pn-essos = "${WESTEROS_VERSION}"
PR:pn-essos = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-essos = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-essos = "${WESTEROS_SRCREV}"

PV:pn-westeros-sink = "${WESTEROS_VERSION}"
PR:pn-westeros-sink = "${WESTEROS_REVISION}"
PACKAGE_ARCH:pn-westeros-sink = "${VENDOR_LAYER_EXTENSION}"
SRCREV:pn-westeros-sink = "${WESTEROS_SRCREV}"

PV:pn-wayland-default-egl = "1.20.0"
PR:pn-wayland-default-egl = "r0"
PACKAGE_ARCH:pn-wayland-default-egl = "${VENDOR_LAYER_EXTENSION}"

