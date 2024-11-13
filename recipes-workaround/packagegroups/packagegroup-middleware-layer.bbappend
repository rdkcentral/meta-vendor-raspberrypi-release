
RDEPENDS:${PN}:remove += " xdial \
                           systimemgrfactory \
                           systimemgrinetrface \
                           systimemgr \
                           webcfg \
                           ctrlm-main \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "
