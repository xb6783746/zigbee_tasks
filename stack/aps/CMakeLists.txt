
set(SRC 
        src/aps_main.c 
        src/aps_dups.c 
        src/aps_bind.c 
        src/aps_commands.c 
        src/aps_nwk_confirm.c 
)

add_library(aps OBJECT ${SRC})

target_include_directories(
    aps PRIVATE
    include
)

