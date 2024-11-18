
RDEPENDS:${PN}:remove += " xdial \
                           webcfg \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "
