
add_library(
        ledpwm
        src/led_controller.c
        src/pwm_configuration.c
        src/pwm_controller.c
)

target_link_libraries(
        ledpwm
        zboss
)

target_include_directories(
        ledpwm PUBLIC
        include
)

target_include_directories(
        ledpwm PRIVATE
        include/internal
)

target_compile_definitions(
        ledpwm PUBLIC
        -DUSE_PWM_TIM1
)

