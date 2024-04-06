cmake_minimum_required(VERSION 3.29.0)
project(SpreadSheet)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES "src/main.cpp" "src/SpreadSheet.cpp" "src/Cell.cpp")

file(GLOB_RECURSE HDR_FILES "headers/SpreadSheet.h" "headers/Cell.h")

add_executable(SpreadSheet ${SRC_FILES} ${HDR_FILES})

set_property(TARGET SpreadSheet PROPERTY CXX_STANDARD 20)

