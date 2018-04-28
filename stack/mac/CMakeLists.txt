
set(SRC
        src/mac.c
        src/mac_cr_coordinator.c
        src/mac_fcs.c
        src/zb_uz2400.c
        src/mac_scan.c
        src/mac_cr_associate.c
        src/mac_associate.c
        src/zb_ns3.c
        src/mac_data.c
        src/mac_cr_data.c
        src/mac_common.c
        src/mac_routines.c
        src/zb_uz2x_common.c
        src/mac_disturber.c
        src/zb_cc25xx.c
        src/zb_cc25xx_common.c
        src/zb_mrf24j40.c
        src/zb_uz2410.c
        )

add_library(mac OBJECT ${SRC})

target_include_directories(
        mac PRIVATE
        include
)
