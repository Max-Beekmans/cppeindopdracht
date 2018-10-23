 //
// Created by MaxBe on 10/22/2018.
//

#include <iostream>
#include "Dungeon.h"
#include "Hall.h"
#include "Room.h"
#include "nostd/Random.h"

Dungeon::Dungeon(const int width, const int height) : _width(width), _height(height) {
    this->_dungeon = new Room*[width];
    for(int i = 0; i < width; ++i) {
        this->_dungeon[i] = new Room[height];
    }
}

void Dungeon::GenerateDungeon() {
    nostd::Random r{};
    int max = (_width * _height) / 2;
    int count = 0;
    this->_rooms = new Room[max];
    this->_halls = new Hall[max * 2];

    //if start == nullptr, find random start
    if (this->_begin == nullptr) {
        int x = r.getRand(0, _width - 1);
        int y = r.getRand(0, _height - 1);
        Coordinate c{x, y};
        this->_begin = new Room(_roomCount++, c);
        this->_begin->IsStart = true;
        this->_begin->IsFilledRoom = true;
        this->_begin->IsVisited = true;
    }
    //add begin to rooms
    this->_rooms[count] = *this->_begin;

    for (int i = 0; i < max; i++) {
        Room current = _rooms[count];
        //loop through possible edges
        //north
        if (current.coords.x != 0 || current.north != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y - 1};
                Room north_room = *new Room(_roomCount++, c);
                _rooms[++count] = north_room;
                Coordinate enda = Coordinate{current.coords};
                Coordinate endb = Coordinate{north_room.coords};
                current.north = new Hall(enda, endb);
            }
        }

    }

    this->_halls = new Hall[_roomCount];

    this->_begin = &this->_dungeon[0][0];
    this->_begin->IsStart = true;
}

void Dungeon::PrintDungeon() {
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            std::cout << this->_dungeon[i][j].GetChar();

        }
        std::cout << std::endl;
    }
}
