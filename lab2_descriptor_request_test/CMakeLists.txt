

set(LINK pthread zboss)

add_executable(router
        src/main.c
        src/response_callbacks.c
        src/controller.c
        src/response_logger.c
        src/simple_descr_parser.c
)

target_include_directories(
        router PUBLIC
        include
)

target_link_libraries(
        router
        ${LINK}
)


