 //
// Created by MaxBe on 10/22/2018.
//

#include <iostream>
#include "Dungeon.h"
#include "Hall.h"
#include "Room.h"
#include "nostd/Random.h"

Dungeon::Dungeon(const int width, const int height) : _width(width), _height(height) {
    this->_dungeon = new Room*[width];
    for(int i = 0; i < width; ++i) {
        this->_dungeon[i] = new Room[height];
    }
    this->_roomCount = 0;
}

void Dungeon::GenerateDungeon() {
    nostd::Random r{};
    int max = (_width * _height) / 2;
    int count = 0;
    this->_rooms = nostd::Array<Room>(max);
    this->_halls = nostd::Array<Hall>(max*2);

    //if start == nullptr, find random start
    if (this->_begin == nullptr) {
        int x = r.getRand(0, _width - 1);
        int y = r.getRand(0, _height - 1);
        Coordinate c{x, y};
        this->_begin = new Room(_roomCount++, c);
        this->_begin->IsStart = true;
        this->_begin->IsFilledRoom = true;
        this->_begin->IsVisited = true;
    }
    //add begin to rooms
    this->_rooms.addBack(*this->_begin);

    for (int i = 0; i < max; i++) {
        if (!_rooms[count].IsFilledRoom) {
            break;
        }
        Room current = _rooms[count];
        Coordinate c{current.coords};
        Coordinate d{current.coords.x, current.coords.y};
        current.IsVisited = true;
        current.IsFilledRoom = true;

        //loop through possible edges
        //north
        if (current.coords.x != 0 && current.north != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y - 1};
                Room north_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    north_room = this->_dungeon[c.x][c.y];
                } else {
                    north_room = *new Room(_roomCount++, c);
                    _rooms.addBack(north_room);
                }
                north_room.IsFilledRoom = true;
                _dungeon[c.x][c.y] = north_room;
                //for debug
                north_room.IsVisited = true;
                Coordinate enda = Coordinate{current.coords};
                Coordinate endb = Coordinate{north_room.coords};
                current.north = new Hall(enda, endb);
            }
        }

        //south
        if (current.coords.y != _height - 1 && current.south != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y + 1};
                Room south_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    south_room = this->_dungeon[c.x][c.y];
                } else {
                    south_room = *new Room(_roomCount++, c);
                    _rooms.addBack(south_room);
                }
                south_room.IsFilledRoom = true;
                _dungeon[c.x][c.y] = south_room;
                //for debug
                south_room.IsVisited = true;
                Coordinate enda = Coordinate{current.coords};
                Coordinate endb = Coordinate{south_room.coords};
                current.south = new Hall(enda, endb);
            }
        }

        //east
        if (current.coords.x != _width - 1 && current.east != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
                //new north coordinate
                Coordinate c{current.coords.x + 1, current.coords.y};
                Room east_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    east_room = this->_dungeon[c.x][c.y];
                } else {
                    east_room = *new Room(_roomCount++, c);
                    _rooms.addBack(east_room);
                }
                east_room.IsFilledRoom = true;
                _dungeon[c.x][c.y] = east_room;
                //for debug
                east_room.IsVisited = true;
                Coordinate enda = Coordinate{current.coords};
                Coordinate endb = Coordinate{east_room.coords};
                current.east = new Hall(enda, endb);
            }
        }

        //west
        if (current.coords.x != 0 && current.west != nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 50) {
                //new north coordinate
                Coordinate c{current.coords.x - 1, current.coords.y};
                Room west_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    west_room = this->_dungeon[c.x][c.y];
                } else {
                    west_room = *new Room(_roomCount++, c);
                    _rooms.addBack(west_room);
                }
                west_room.IsFilledRoom = true;
                _dungeon[c.x][c.y] = west_room;
                //for debug
                west_room.IsVisited = true;
                Coordinate enda = Coordinate{current.coords};
                Coordinate endb = Coordinate{west_room.coords};
                current.west = new Hall(enda, endb);
            }
        }
        _dungeon[c.x][c.y] = current;
    }
}

void Dungeon::PrintDungeon() {
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            std::cout << this->_dungeon[i][j].GetChar();
        }
        std::cout << std::endl;
    }
}
