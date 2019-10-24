cmake_minimum_required(VERSION 3.10)
project(eindopdracht)

set(CMAKE_CXX_STANDARD 11)
configure_file(src/readables/afstanden_tussen_steden.csv afstanden_tussen_steden.csv COPYONLY)
configure_file(src/readables/goederen_hoeveelheid.csv goederen_hoeveelheid.csv COPYONLY)
configure_file(src/readables/goederen_prijzen.csv goederen_prijzen.csv COPYONLY)
configure_file(src/readables/schepen.csv schepen.csv COPYONLY)

#add_subdirectory(src)
add_subdirectory(test)

add_executable(eindopdracht
        src/main.cpp
        src/nostd/Random.h
        src/nostd/String.cpp
        src/nostd/String.h
        src/nostd/Array.h
        src/FileReader.cpp
        src/FileReader.h
        src/nostd/IOHandler.h
        src/Ship.h
        src/Cannon.h
        src/nostd/Range.h
        src/Cargo.h
        src/Game.cpp
        src/Game.h
        src/Player.h
        src/Port.cpp
        src/Port.h
        src/Factory/PortFactory.cpp
        src/Factory/PortFactory.h
        src/exceptions/PortNotFoundException.h
        src/StateManager.h
        src/StateManager.cpp
        src/BaseState.h
        src/nostd/Stack.h
        src/DockedState.h
        src/DockedState.cpp
        src/SailingState.h
        src/SailingState.cpp
        src/FightingState.cpp
        src/FightingState.h
        src/Factory/Factory.h
        src/Factory/ShipFactory.cpp
        src/Factory/ShipFactory.h
        src/exceptions/OutOfFileException.h)

