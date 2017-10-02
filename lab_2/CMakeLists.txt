cmake_minimum_required(VERSION 3.8)
project(lab_2)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c matrix.c)
add_executable(lab_2 ${SOURCE_FILES})