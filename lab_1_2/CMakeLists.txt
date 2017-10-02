cmake_minimum_required(VERSION 3.8)
project(lab_1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c keyval.c dict.c)
add_executable(lab_1 ${SOURCE_FILES})