//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_DUNGEON_H
#define EINDOPDRACHT_DUNGEON_H

#include "nostd/Array.h"
#include "Hall.h"
#include "Room.h"
#include "Monster.h"

class Dungeon {
public:
    Dungeon(const int width, const int height);
    void GetMonsters();
    void GenerateDungeon();
    void PrintDungeon();
private:
    //direction 1 north, 2 east, 3 south, 4 west
    //rest is return nullptr
    //Hall* GenerateHall(const Room& current, int direction);
    Room** _dungeon;
    Room* _begin = nullptr;
    nostd::Array<Room> _rooms;
    nostd::Array<Hall> _halls;
    nostd::Array<Monster> _monsters;
    const int _width;
    const int _height;
    int _roomCount;
};


#endif //EINDOPDRACHT_DUNGEON_H
