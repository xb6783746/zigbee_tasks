

set(LINK pthread zboss)

add_executable(coordinatorx10
        src/coordinator.c
        src/tmp.c
)

add_executable(ed_x10
        src/ed_1.c
        src/tmp.c
)

target_link_libraries(
        coordinatorx10
        ${LINK}
)

target_link_libraries(
        ed_x10
        ${LINK}
)



