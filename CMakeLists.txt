cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

project(MHCLib)

include_directories(${CMAKE_SOURCE_DIR}/common)

add_subdirectory(data_structures)
add_subdirectory(algorithms)
add_subdirectory(demo)