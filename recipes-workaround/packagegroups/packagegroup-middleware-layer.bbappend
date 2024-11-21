
RDEPENDS:${PN}:remove += " xdial \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "
