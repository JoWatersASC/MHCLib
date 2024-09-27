cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_NAME "MHCds")

include_directories(include funcs)

add_library(${LIB_NAME} SHARED
    funcs/list_funcs.cpp
    include/vector.hpp
    include/queue.hpp
    include/stack.hpp
    include/set.hpp
    include/map.hpp

    include/list.hpp
)

target_include_directories(${LIB_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/common
)