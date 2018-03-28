 

add_executable(dump_converter dump_converter.c)
add_executable(dump_parse dump_parse.c)
add_executable(hex_to_bin hex_to_bin.c)

target_link_libraries(
    dump_converter PUBLIC
    pcap
    xml2
)
