cmake_minimum_required(VERSION 3.29.0)
project(vector)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(headers)

set(SRC_FILES
    "src/main.cpp"
)

set(HDR_FILES
    "headers/vector.h"
    "src/vector.hpp" 
)

add_executable(vector ${SRC_FILES})

set_property(TARGET vector PROPERTY CXX_STANDARD 20)
