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
        src/nostd/String.h
        src/nostd/Array.h
        src/FileReader.cpp
        src/FileReader.h
        src/nostd/IOHandler.h
        src/models/Ship.h
        src/models/Cannon.h
        src/nostd/Range.h
        src/models/Cargo.h
        src/controllers/GameController.cpp
        src/controllers/GameController.h
        src/models/Port.cpp
        src/models/Port.h
        src/factories/PortFactory.cpp
        src/factories/PortFactory.h
        src/exceptions/PortNotFoundException.h
        src/factories/Factory.h
        src/factories/ShipFactory.cpp
        src/factories/ShipFactory.h
        src/exceptions/OutOfFileException.h src/controllers/GameController.h
        src/controllers/PortController.cpp
        src/controllers/PortController.h
        src/controllers/FightingController.cpp
        src/controllers/FightingController.h
        src/controllers/SailingController.cpp
        src/controllers/SailingController.h
        )
