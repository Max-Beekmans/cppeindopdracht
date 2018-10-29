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
    Room GetRoom(const int x, const int y);

    Coordinate begin;
    Coordinate end;
    Coordinate stair_up;
    Coordinate stair_down;
private:
    void copy_from(const Dungeon& copy);
    void move_from(Dungeon& move);
    void SetStairs(const int layer);

    nostd::Array<Room*> _dungeon;
    nostd::Array<Room*> _rooms;
    nostd::Array<Hall> _halls;
    nostd::Array<Monster> _monsters;
    int _width;
    int _height;
    int _roomCount;
    int _level;
};


#endif //EINDOPDRACHT_DUNGEON_H
