//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_ROOM_H
#define EINDOPDRACHT_ROOM_H

#include "Hall.h"
#include "nostd/String.h"

class Room {
public:
    Room();
    ~Room();
    Room(const int Id, const Coordinate c);
    Room(const Room& r);
    Room(Room&& r);

    Room& operator=(const Room& copy);
    Room& operator=(Room&& move) noexcept;

    char GetChar();
    nostd::String GetDescription();

    Hall north;
    Hall south;
    Hall east;
    Hall west;
    Coordinate coords;
    //Yes this can be way prettier...
    //0 = Small, 1 = Medium or 2 = large
    int size = 0;
    //0 = empty, 1 = 4 chair and a table, 2 = bed
    int layout = 0;
    bool IsClean = false;

    bool IsStart = false;
    bool IsEndBoss = false;
    bool IsStairUp = false;
    bool IsStairDown = false;
    bool IsVisited = false;
    //even dots that aren't visitable rooms are still rooms but defaultConstructed just with this bool on false.
    //this makes it allot easier to represent a Room**
    bool IsFilledRoom = false;
    int _Id;
private:
    //int _Id;
    void copy_from(const Room& r);
    void move_from(Room& r);
};


#endif //EINDOPDRACHT_ROOM_H
