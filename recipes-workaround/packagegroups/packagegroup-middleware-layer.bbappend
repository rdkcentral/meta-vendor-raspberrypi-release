
RDEPENDS:${PN}:remove += " xdial \
                           webcfg \
                           ctrlm-main \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "
