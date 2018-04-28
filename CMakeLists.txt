
cmake_minimum_required(VERSION 3.7)

enable_language(C)
enable_language(ASM)

include_directories(
        stack/include
        stack/osif/include
        stack/osif/cortexm4/SPL_inc
        stack/osif/cortexm4/board
)

add_definitions(
        -DSTM32F40_41xxx
)

#include(Options)
include(Cortexm4-Options)

add_subdirectory(stack)
add_subdirectory(lab2_data_request_test)
add_subdirectory(lab3_descriptor_request_test)
add_subdirectory(lab4_stm32)