LIC_FILES_CHKSUM = "file://LICENSE;md5=291858d2271fa690cffedb2d0abc5c11"
SRCREV = "3c23af336e05329ee895b05c8e728ac1008d0241"

# Temporary fix for fetch-time LFS/network issues, until DNS/proxy/access (or internal mirror) for GitHub LFS.
SRC_URI = "${CMF_GITHUB_ROOT}/ralf-utils.git;protocol=${CMF_GITHUB_PROTOCOL};${CMF_GITHUB_BRANCH};lfs=0"
