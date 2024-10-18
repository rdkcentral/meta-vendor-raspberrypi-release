DESCRIPTION = "Relaese uImage and dtb"
SECTION = "core"
LICENSE = "MIT"

inherit bin_package
inherit kernel

LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
COMPATIBLE_MACHINE = "^rpi$"

VERSION = "5.15.92-v8"
PV = "5.15.92"
PR = "r0"

SRC_URI = "\
   ${VENDOR_IPK_SERVER_PATH}/kernel-image-image-${VERSION}_${PV}-${PR}_${MACHINE}-vendor.ipk;subdir=${BP};name=vendor-linux \
   ${VENDOR_IPK_SERVER_PATH}/kernel-devicetree_${PV}-${PR}_${MACHINE}-vendor.ipk;subdir=${BP};name=vendor-dtb \
   "

SRC_URI[vendor-linux.sha256sum] = "8d2f66e8a8a350ea83f6928876b08c7253cf10b9a5236de51dc6f5b1b27f903b"
SRC_URI[vendor-dtb.sha256sum] = "99f2022473aa6e19944a8b09febcae07f74fe5c2bfb9e78a92b5b6c1cb8a046d"

do_unpack_extra() {
    mkdir -p ${S}
    mkdir -p ${WORKDIR}
    mkdir -p ${BP}
}

addtask unpack_extra  after do_fetch before do_unpack
do_configure[noexec] = "1"
do_compile[noexec] = "1"
do_prepare_recipe_sysroot[noexec] = "1"
do_shared_workdir[noexec] = "1"
do_kernel_link_images[noexec] = "1"
do_package[noexec] = "1"
do_packagedata[noexec] = "1"
do_package_write_ipk[noexec] = "1"
do_deploy[noexec] = "1"
do_package_qa[noexec] = "1"
do_install[noexec] = "1"

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_SYSROOT_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT= "1"

python do_package_custom_write_ipk(){
    manifest_name = d.getVar("SSTATE_MANFILEPREFIX", True) + ".package_write_ipk"
    bb.note(" manifest_name %s"  % manifest_name)
    manifest_file = open(manifest_name, "w")
    manifest_file.close()
}
addtask do_package_custom_write_ipk after do_install_image before do_build

python do_custom_package(){
    kernel_depmod = oe.path.join(d.getVar('PKGDATA_DIR'), "kernel-depmod")
    bb.utils.mkdirhier(kernel_depmod)
    kernel_abi_ver_file = oe.path.join(d.getVar('PKGDATA_DIR'), "kernel-depmod",
                                           'kernel-abiversion')
    linux_ver = d.getVar("VERSION")
    with open(kernel_abi_ver_file, "w") as abi_ver_file:
        abi_ver_file.write("%s" % linux_ver)
}
addtask do_custom_package after do_install_image before do_build

do_install_image () {
        install -d ${DEPLOY_DIR_IMAGE}
        install -m 0644 ${WORKDIR}/android-raspberrypi-${PV}/boot/* ${DEPLOY_DIR_IMAGE}
}
addtask do_install_image after do_unpack before do_build
