cmake_minimum_required(VERSION 3.29.0)
project(vector)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(headers)

set(SRC_FILES
    "src/main.cpp"  
    "src/vector.hpp" 
)

set(HDR_FILES
    "headers/g3/vector.h"
)

add_executable(vector ${SRC_FILES})

set_property(TARGET vector PROPERTY CXX_STANDARD 20)
