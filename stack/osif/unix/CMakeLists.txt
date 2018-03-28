
set(SRC 
        src/zb_trace_unix.c
        src/zb_mac_transport_linux_pipes.c 
        src/zb_mac_transport_linux_spidev.c
)

add_library(osif OBJECT ${SRC})

target_include_directories(
    osif PRIVATE
    include
)
