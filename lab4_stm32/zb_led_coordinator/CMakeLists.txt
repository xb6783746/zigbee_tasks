
add_executable(
        zb_led_coordinator

        src/handlers/power_button_handler.c
        src/handlers/level_button_handler.c
        src/handlers/button_interrupt_handler.c

        src/main.c
        src/init.c
        src/button_controller.c
        src/command_sender.c
        src/startup_stm32f407xx.S
        src/system_stm32f4xx.c
)

target_link_libraries(
        zb_led_coordinator
        zboss
)

target_include_directories(
        zb_led_coordinator PUBLIC
        include
)