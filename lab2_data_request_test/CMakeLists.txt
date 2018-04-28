
include_directories(
        include
)

set(LINK pthread zboss)

add_executable(controller
        controller/command_sender.c
        controller/main.c
        controller/command_generator.c
)

target_include_directories(
        controller PUBLIC
        controller/include
)

add_executable(led
        led/main.c
        led/led_controller.c
        led/led.c
)

target_include_directories(
        led PUBLIC
        led/include
)

target_link_libraries(
        controller
        ${LINK}
)

target_link_libraries(
        led
        ${LINK}
)


