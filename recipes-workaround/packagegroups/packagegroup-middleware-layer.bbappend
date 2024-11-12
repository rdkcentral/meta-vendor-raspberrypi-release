
RDEPENDS:${PN}:remove += " rdksysctl \
                           xdial \
                           systimemgrfactory \
                           systimemgrinetrface \
                           systimemgr \
                           webcfg \
                           fdk-aac \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "
