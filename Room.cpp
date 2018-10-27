//
// Created by MaxBe on 10/22/2018.
//

#include "Room.h"

Room::Room() {
    this->_Id = -1;
    this->coords = {};
    this->north = nullptr;
    this->south = nullptr;
    this->east = nullptr;
    this->west = nullptr;
}

Room::~Room() {
//    delete north;
//    delete south;
//    delete west;
//    delete east;
}

Room::Room(const int Id, const Coordinate c) : _Id(Id), coords(c) {
    this->north = nullptr;
    this->south = nullptr;
    this->east = nullptr;
    this->west = nullptr;
}

Room::Room(const Room &r) {
    copy_from(r);
}

Room::Room(Room &&r) {
    move_from(r);
}

//overrule the char get if
//1. this room is unvisited (default is also '.')
//2. this room is the entrance to the dungeon
//3. this room is the final boss room
//4. this room is a stair
char Room::GetChar() {
    if (!IsVisited) {
        return '.';
    }

    if (IsStart) {
        return 'S';
    }

    if (IsEndBoss) {
        return 'E';
    }

    if (IsStairUp) {
        return 'H';
    }

    if (IsStairDown) {
        return 'L';
    }

    return 'N';
}

Room &Room::operator=(const Room &copy) {
    if (this == &copy) return *this;
    copy_from(copy);
    return *this;
}

Room &Room::operator=(Room&& move) noexcept {
    if (this == &move) return *this;
    move_from(move);
    return *this;
}

//copy operation used in constructor and operator
void Room::copy_from(const Room& r) {
    this->_Id = r._Id;
    this->IsStart = r.IsStart;
    this->IsEndBoss = r.IsEndBoss;
    this->IsStairUp = r.IsStairUp;
    this->IsStairDown = r.IsStairDown;
    this->IsVisited = r.IsVisited;
    this->coords = r.coords;
    this->IsFilledRoom = r.IsFilledRoom;
    this->north = r.north;
    this->east = r.east;
    this->south = r.south;
    this->west = r.west;
}

//move operation used in constructor and operator
void Room::move_from(Room& r) {
    this->_Id = r._Id;
    this->IsStart = r.IsStart;
    this->IsEndBoss = r.IsEndBoss;
    this->IsStairUp = r.IsStairUp;
    this->IsStairDown = r.IsStairDown;
    this->IsVisited = r.IsVisited;
    this->coords = r.coords;
    this->IsFilledRoom = r.IsFilledRoom;
    this->north = r.north;
    this->east = r.east;
    this->south = r.south;
    this->west = r.west;
    r.north = nullptr;
    r.east = nullptr;
    r.south = nullptr;
    r.west = nullptr;
}




