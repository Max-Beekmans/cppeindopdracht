cmake_minimum_required(VERSION 3.12)
project(eindopdracht)

set(CMAKE_CXX_STANDARD 11)

add_executable(eindopdracht main.cpp nostd/String.cpp nostd/String.h nostd/Array.cpp nostd/Array.h)