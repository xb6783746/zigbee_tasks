
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++) 

set(PLATFORM unix)

set(PLATFORM_DEFINES -DZB_PLATFORM_LINUX_PC32)

set(TRACE_DEFINES -DZB_TRACE_LEVEL=4 -DZB_TRACE_MASK=-1)
set(DEBUG_DEFINES -DDEBUG ${TRACE_DEFINES})
set(DEBUG_CFLAGS -g)
set(RELEASE_CFLAGS -O3)
set(PROFILE_CFLAGS -g -O3 -pg)
set(WERROR -Werror)
set(WARN_OPTIONS -W -Wall -Wpointer-arith -Wcast-align -std=gnu99 -Wno-format-zero-length -Wno-format-zero-length -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -Wno-unused-but-set-variable -Wno-unused-local-typedefs)
set(WARN_OPTIONS_CXX -W -Wall -Wpointer-arith -Wcast-align -pedantic)
set(CFLAGS_BUILD_CFG ${DEBUG_CFLAGS})

set(DEFINES ${PLATFORM_DEFINES} ${DEBUG_DEFINES})
set(CFLAGS ${CFLAGS_BUILD_CFG} ${CFLAGS_USER} -pipe ${WARN_OPTIONS} -fno-strict-aliasing ${WERROR})

set(CXXFLAGS ${CFLAGS_BUILD_CFG} ${CFLAGS_USER} -pipe ${WARN_OPTIONS_CXX} -fno-strict-aliasing ${WERROR})

SET(CMAKE_CXX_FLAGS ${COMMON_FLAGS})
SET(CMAKE_C_FLAGS ${COMMON_FLAGS})

add_definitions(${DEFINES})
