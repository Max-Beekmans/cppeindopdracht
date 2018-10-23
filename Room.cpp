//
// Created by MaxBe on 10/22/2018.
//

#include "Room.h"

Room::Room() {
    this->_Id = -1;
}

Room::~Room() {
    //no memory to free yet
}

Room::Room(const int Id) {
    this->_Id = Id;
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
}

//move operation used in constructor and operator
void Room::move_from(Room& r) {
    this->_Id = r._Id;
    this->IsStart = r.IsStart;
    this->IsEndBoss = r.IsEndBoss;
    this->IsStairUp = r.IsStairUp;
    this->IsStairDown = r.IsStairDown;
    this->IsVisited = r.IsVisited;
}




