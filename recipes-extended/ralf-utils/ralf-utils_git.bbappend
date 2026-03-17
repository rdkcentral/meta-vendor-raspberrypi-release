LIC_FILES_CHKSUM = "file://LICENSE;md5=c6bff120d1436ef6f655d08d03f95cff"
SRCREV = "3c23af336e05329ee895b05c8e728ac1008d0241"
# Work around transient Git LFS/DNS failures during fetch/unpack.
export GIT_LFS_SKIP_SMUDGE = "1"
export GIT_LFS_SKIP_DOWNLOAD_ERRORS = "1"

do_fetch:prepend() {
    export GIT_LFS_SKIP_SMUDGE=1
    export GIT_LFS_SKIP_DOWNLOAD_ERRORS=1
}

do_unpack:prepend() {
    export GIT_LFS_SKIP_SMUDGE=1
    export GIT_LFS_SKIP_DOWNLOAD_ERRORS=1
}
