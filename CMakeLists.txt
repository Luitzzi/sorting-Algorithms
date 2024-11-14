cmake_minimum_required(VERSION 3.29)
project(sorting_program C)

set(CMAKE_C_STANDARD 11)
include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(sorting_program ${SOURCES})
target_include_directories(sorting_program PRIVATE include)
target_link_libraries(sorting_program m)