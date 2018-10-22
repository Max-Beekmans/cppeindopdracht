//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_DUNGEON_H
#define EINDOPDRACHT_DUNGEON_H

#include "Room.h"

class Dungeon {
public:
    Dungeon(const int width, const int height);
    void GenerateDungeon();
    void PrintDungeon();
private:
    Room** _dungeon;
    Room* _begin;
    const int _width;
    const int _height;
    int _roomCount;
};


#endif //EINDOPDRACHT_DUNGEON_H
