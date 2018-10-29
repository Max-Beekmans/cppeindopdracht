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
    Dungeon();
    explicit Dungeon(const int width, const int height, const int level);
    ~Dungeon();
    Dungeon(const Dungeon& copy);
    Dungeon(Dungeon&& move) noexcept;

    Dungeon& operator=(const Dungeon& copy);
    Dungeon& operator=(Dungeon&& move) noexcept;

    void GetMonsters();
    void GenerateDungeon();
    void PrintDungeon();
private:
    Hall* GenerateEdge(Coordinate c, Room* current, Room* r);
    void copy_from(const Dungeon& copy);
    void move_from(Dungeon& move);
    Room** _dungeon;
    Room* _begin = nullptr;
    nostd::Array<Room*> _rooms;
    nostd::Array<Hall> _halls;
    nostd::Array<Monster> _monsters;
    int _width;
    int _height;
    int _roomCount;
    int _level;
};


#endif //EINDOPDRACHT_DUNGEON_H
