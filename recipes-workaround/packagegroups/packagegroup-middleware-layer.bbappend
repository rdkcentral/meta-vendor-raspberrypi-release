DEPENDS:remove += " curl-netflix"

RDEPENDS:${PN}:remove += " remotedebugger\
                           rdksysctl \
                           xdial \
                           systimemgrfactory \
                           systimemgrinetrface \
                           systimemgr \
                           webcfg \
                           ctrlm-main \
                           fdk-aac \
                           virtual/ca-certificates-trust-store \
                         "

RDEPENDS:${PN}:append = " ca-certificates-default-certs "

