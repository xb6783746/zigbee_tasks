
add_executable(
        zb_led_device

        src/main.c
        src/init.c
        src/led_controller.c
        src/led.c
        src/system_stm32f4xx.c
        src/startup_stm32f407xx.S
)

target_link_libraries(
        zb_led_device
        zboss
        ledpwm
)

target_include_directories(
        zb_led_device PUBLIC
        include
        include/utils
)


target_compile_definitions(
        zb_led_device PUBLIC
        -DBRIGHTNESS_BUTTON_LINE=0
        -DCHANNEL_BUTTON_LINE=1
)

