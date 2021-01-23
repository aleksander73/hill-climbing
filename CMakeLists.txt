cmake_minimum_required(VERSION 3.5)
include_directories(include)
file(GLOB_RECURSE SOURCES main.cpp "src/*.cpp")
add_executable(hill-climbing ${SOURCES})
