
set(SRC 
    network_simulator.cpp 
    xgml_load.cpp 
    zigbee_stuff.cpp 
    mac_frame.cpp
)

add_executable(network_simulator ${SRC})

target_include_directories(
    network_simulator PUBLIC
    /usr/include/libxml2
)

target_link_libraries(
    network_simulator
    xml2
)
