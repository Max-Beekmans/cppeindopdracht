//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_ROOM_H
#define EINDOPDRACHT_ROOM_H

#include "Hall.h"

class Room {
public:
    Room();
    ~Room();
    Room(const int Id, const Coordinate c);
    Room(const Room& r);
    Room(Room&& r);

    Room& operator=(const Room& copy);
    Room& operator=(Room&& move) noexcept;

    Hall* north;
    Hall* south;
    Hall* east;
    Hall* west;

    Coordinate coords;

    char GetChar();
    bool IsStart = false;
    bool IsEndBoss = false;
    bool IsStairUp = false;
    bool IsStairDown = false;
    bool IsVisited = false;
    //even dots that aren't visitable rooms are still rooms but just with this bool on false.
    //this makes it allot easier to represent a Room**
    bool IsFilledRoom = false;
private:
    int _Id;
    void copy_from(const Room& r);
    void move_from(Room& r);
};


#endif //EINDOPDRACHT_ROOM_H
