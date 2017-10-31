cmake_minimum_required(VERSION 3.8)
project(lab_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Item.cpp Book.cpp Magazin.cpp)
add_executable(lab_6 ${SOURCE_FILES})