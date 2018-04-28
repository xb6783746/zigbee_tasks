
set(SRC 
        src/secur_ccm.c
        src/apsme_secur.c 
        src/zdo_secur.c 
        src/nwk_secur.c 
        src/aps_secur.c
        src/mac_secur.c
        src/zb_TI_cc25xx_secur_ccm.c
)

add_library(secur OBJECT ${SRC})

target_include_directories(
    secur PRIVATE
    include
)
