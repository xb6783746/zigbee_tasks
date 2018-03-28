
set(SRC 
        src/zdo_app.c 
        src/zdo_rx.c
        src/zdo_disc_cli.c 
        src/af_rx.c 
        src/zdo_disc_srv.c 
        src/af_descriptor.c 
        src/zdo_common.c 
        src/zdo_nwk_manage_cli.c 
        src/zdo_nwk_manage_srv.c
        src/zdo_channel_manager.c 
        src/test_profile.c 
        src/zdo_bind_manage.c
)

add_library(zdo OBJECT ${SRC})

target_include_directories(
    zdo PRIVATE
    include
)
