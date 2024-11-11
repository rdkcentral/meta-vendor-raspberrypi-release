# TODO: Remove when RDK-54002 gets fixed.
# Without this flag aamp playback is resulting in black screen without any errors.
CXXFLAGS += "-DNO_NATIVE_AV -DPLAYBINTEST_WESTEROSSINK"
