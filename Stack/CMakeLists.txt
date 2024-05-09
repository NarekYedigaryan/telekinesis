cmake_minimum_required(VERSION 3.29.0)
project(stack)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(headers)

set(SRC_FILES
    "src/main.cpp"
)

set(HDR_FILES
    "headers/stack.h"
    "src/stack.hpp" 
)

add_executable(stack ${SRC_FILES})

set_property(TARGET stack PROPERTY CXX_STANDARD 20)
