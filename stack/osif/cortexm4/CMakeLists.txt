
set(SRC
        SPL_src/misc.c
        SPL_src/stm32f4xx_crc.c
        SPL_src/stm32f4xx_exti.c
        SPL_src/stm32f4xx_gpio.c
        SPL_src/stm32f4xx_i2c.c
        SPL_src/stm32f4xx_rcc.c
        SPL_src/stm32f4xx_spi.c
        SPL_src/stm32f4xx_syscfg.c
        SPL_src/stm32f4xx_tim.c
        SPL_src/stm32f4xx_usart.c

        zb_cortexm4_exti.c
        zb_cortexm4_time.c
        zb_trace_cortexm4.c
        zb_transport_cortexm4.c
        zb_cortexm4_spi.c
        zb_cortexm4_usart.c
)

add_library(osif OBJECT ${SRC})

target_include_directories(
    osif PUBLIC
    SPL_inc
    board
)
