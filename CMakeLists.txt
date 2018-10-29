cmake_minimum_required(VERSION 3.12)
project(eindopdracht)

set(CMAKE_CXX_STANDARD 11)
configure_file(readables/monsters.txt monsters.txt COPYONLY)

add_executable(eindopdracht main.cpp nostd/Random.h nostd/String.cpp nostd/String.h nostd/Array.h nostd/IOHandler.cpp nostd/IOHandler.h Dungeon.cpp Dungeon.h Room.cpp Room.h Hall.h Coordinate.h Hero.h Hero.cpp Monster.cpp Monster.h Game.cpp Game.h Item.cpp Item.h)
