cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_NAME "MHCds")

include_directories(include funcs)

set(HEADERS
    include/list.h
    include/stack.h
    include/queue.h
)
set(IMPLEMENTATIONS
    impl/list.hpp
    impl/stack.hpp
    impl/queue.hpp
)

add_library(${LIB_NAME} SHARED
    src/mhcds.cpp
    include/ds_common.h

    ${HEADERS}
    ${IMPLEMENTATIONS}
    # include/vector.hpp
    # include/queue.hpp
    # include/set.hpp
    # include/map.hpp    
)

target_include_directories(${LIB_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/common
)

source_group("Implementation Files" FILES ${IMPLEMENTATIONS})
source_group("Header Files" FILES ${HEADERS})