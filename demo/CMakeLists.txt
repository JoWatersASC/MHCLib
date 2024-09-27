cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demo src/main.cpp)

target_include_directories(demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(demo MHCds MHCalgo)

file(GLOB HEADER_FILES include/*.h)
target_sources(demo PRIVATE ${HEADER_FILES})
source_group("Header Files" FILES ${HEADER_FILES})