cmake_minimum_required(VERSION 3.12)
project(eindopdracht)

set(CMAKE_CXX_STANDARD 11)
configure_file(readables/monsters.txt /monsters.txt COPYONLY)

add_executable(eindopdracht main.cpp nostd/Random.h nostd/String.cpp nostd/String.h nostd/Array.h Dungeon.cpp Dungeon.h Room.cpp Room.h Hall.h Coordinate.h Monster.cpp Monster.h)
