LIC_FILES_CHKSUM = "file://LICENSE;md5=c6bff120d1436ef6f655d08d03f95cff"
SRCREV = "3c23af336e05329ee895b05c8e728ac1008d0241"

python () {
    src_uri = (d.getVar("SRC_URI") or "").split()
    updated = []
    for u in src_uri:
        if u.startswith("git://") and "ralf-utils" in u and "lfs=" not in u:
            u = u + ";lfs=0"
        updated.append(u)
    d.setVar("SRC_URI", " ".join(updated))
}
