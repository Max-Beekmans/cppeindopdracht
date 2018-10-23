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
    int max = (_width * _height) / 2;
    nostd::Random r{};
    this->_rooms[max];

    for (int i = 0; i < max; i++) {
        int x = 0;
        int y = 0;
        x = r.getRand(0, _width - 1);
        y = r.getRand(0, _height - 1);
        _dungeon[x][y] = *new Room(_roomCount++);
        _dungeon[x][y].IsFilledRoom = true;
        //visible for debug purposes
        _dungeon[x][y].IsVisited = true;

        this->_begin = &this->_dungeon[x][y];
        Room* current = this->_begin;
        //loop through possible edges
        //north
        if (x != 0 || current.north != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
//                rooms[i] = new Room(_roomCount++);
//                current.north = new Hall()
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
