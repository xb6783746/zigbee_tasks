
 
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
 

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
 
SET(LINKER_SCRIPT  ${CMAKE_SOURCE_DIR}/stack/osif/cortexm4/board/stm32_f4discovery_flash.ld)

SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

SET(COMMON_FLAGS "-mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -ffreestanding")

SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS}")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=nosys.specs -Wl,--gc-sections -T ${LINKER_SCRIPT}")

