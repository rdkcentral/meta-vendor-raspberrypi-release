#RDK-53835 - Temp fix for telemetry compialtion error
DEPENDS:remove = " mountutils
EXTRA_OECONF:remove = " --enable-mountutils"
