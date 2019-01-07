cmake_minimum_required(VERSION 3.12)
project(eindopdracht)

set(CMAKE_CXX_STANDARD 11)
configure_file(readables/afstanden_tussen_steden.csv afstanden_tussen_steden.csv COPYONLY)
configure_file(readables/goederen_hoeveelheid.csv goederen_hoeveelheid.csv COPYONLY)
configure_file(readables/goederen_prijzen.csv goederen_prijzen.csv COPYONLY)
configure_file(readables/schepen.csv schepen.csv COPYONLY)

add_executable(eindopdracht main.cpp nostd/Random.h nostd/String.cpp nostd/String.h nostd/Array.h nostd/IOHandler.h FileReader.cpp FileReader.h)
