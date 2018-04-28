
set(SRC
        src/zb_debug.c
        src/zb_scheduler.c
        src/zb_bufpool.c
        src/zb_init.c
        src/zb_bufpool_init.c
        src/zb_scheduler_init.c
        src/zb_time.c
        src/zb_ib.c
        src/zb_random.c
        src/zb_trace.c
        src/zb_address.c
)

add_library(common OBJECT ${SRC})

target_include_directories(
    common PRIVATE
    include
)