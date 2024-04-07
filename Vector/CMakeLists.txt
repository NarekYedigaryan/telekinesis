cmake_minimum_required(VERSION 3.29.0)
project(Vector)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES "src/main.cpp" "src/Vector.cpp" )

file(GLOB_RECURSE HDR_FILES "headers/Vector.h" )

add_executable(Vector ${SRC_FILES} ${HDR_FILES})

set_property(TARGET Vector PROPERTY CXX_STANDARD 20)

