

#add_subdirectory(devtools)
add_subdirectory(mac)
add_subdirectory(nwk)
add_subdirectory(secur)
add_subdirectory(zdo)
add_subdirectory(aps)
add_subdirectory(osif/${PLATFORM})
add_subdirectory(common)

add_library(zboss STATIC
        $<TARGET_OBJECTS:mac>
        $<TARGET_OBJECTS:nwk>
        $<TARGET_OBJECTS:secur>
        $<TARGET_OBJECTS:zdo>
        $<TARGET_OBJECTS:aps>
        $<TARGET_OBJECTS:osif>
        $<TARGET_OBJECTS:common>
        )

target_include_directories(
        zboss PUBLIC
        include
        osif/include
)
