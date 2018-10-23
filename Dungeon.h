//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_DUNGEON_H
#define EINDOPDRACHT_DUNGEON_H

#include "nostd/Array.h"
#include "Hall.h"
#include "Room.h"

class Dungeon {
public:
    Dungeon(const int width, const int height);
    void GenerateDungeon();
    void PrintDungeon();
private:
    Room** _dungeon;
    Room* _begin = nullptr;
    nostd::Array<Room> _rooms;
    Hall* _halls;
    int* arr = new int[10];
    const int _width;
    const int _height;
    int _roomCount;
};


#endif //EINDOPDRACHT_DUNGEON_H
