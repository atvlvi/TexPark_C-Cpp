cmake_minimum_required(VERSION 3.8)
project(lab_3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c word.c node.c)
add_executable(lab_3 ${SOURCE_FILES})