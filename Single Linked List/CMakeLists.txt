cmake_minimum_required(VERSION 3.29.0)
project(List)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES "src/main.cpp" "src/forward_list.cpp" )

file(GLOB_RECURSE HDR_FILES "headers/forward_list.h" )

add_executable(List ${SRC_FILES} ${HDR_FILES})

set_property(TARGET List PROPERTY CXX_STANDARD 20)

