
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
)

add_library(mac OBJECT ${SRC})

target_include_directories(
    mac PRIVATE
    include
)
