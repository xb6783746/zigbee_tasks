

set(LINK pthread zboss)

add_executable(router
        src/main.c
)

target_include_directories(
        router PUBLIC
        include
)

target_link_libraries(
        router
        ${LINK}
)


