cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_NAME "MHCalgo")

add_library(${LIB_NAME} STATIC
    src/greedy.cpp
)

target_include_directories(${LIB_NAME} INTERFACE ${INCLUDE_DIR})

file(GLOB HEADER_FILES include/*.h)
target_sources(${LIB_NAME} PRIVATE ${HEADER_FILES})
source_group("Header Files" FILES ${HEADER_FILES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/common)