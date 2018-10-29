//
// Created by MaxBe on 10/22/2018.
//

#include "Room.h"
#include "nostd/Random.h"

Room::Room() {
    this->_Id = -1;
    this->coords = {};
    this->layout = -1;
    this->IsClean = false;
    this->size = -1;
    this->IsStart = false;
    this->IsEndBoss = false;
    this->IsStairUp = false;
    this->IsStairDown = false;
    this->IsVisited = false;
    this->IsFilledRoom = false;
}

Room::~Room() {}

Room::Room(const int Id, const Coordinate c) : _Id(Id), coords(c) {
    nostd::Random r;
    this->layout = r.getRand(0, 2);
    this->size = r.getRand(0, 2);
    int coin = r.getRand(0, 1);
    if (coin == 0) {
        this->IsClean = true;
    } else {
        this->IsClean = false;
    }

    this->IsStart = false;
    this->IsEndBoss = false;
    this->IsStairUp = false;
    this->IsStairDown = false;
    this->IsVisited = true;
    this->IsFilledRoom = true;
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
}

nostd::String Room::GetDescription() {
    //TODO make some wholesome description from layout, size and IsClean
    nostd::String str {"This is a "};
    switch (this->size) {
        case 0:
            str += nostd::String {"small "};
            break;
        case 1:
            str += nostd::String {"moderate "};
            break;
        case 2:
            str += nostd::String {"large "};
            break;
        default:
            break;
    }

    if(this->IsClean) {
        str += nostd::String {"clean room."};
    } else {
        str += nostd::String {"dirty room."};
    }

    switch (this->layout) {
        case 0:
            //isempty
            break;
        case 1:
            str += nostd::String {" There seems to be a table with 4 chairs in the middle of the room."};
            break;
        case 2:
            str += nostd::String {" You can see a faint image of a bed in the corner of the room."};
            break;
        default:
            //isempty
            break;
    }

    return str;
}




