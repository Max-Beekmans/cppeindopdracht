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
    this->PrintDungeon();
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
        //this boolean should be set for all 'build' rooms.
        // We don't want to visit default constructable rooms
        if (!_rooms[count].IsFilledRoom) {
            break;
        }
        Room current = _rooms[count++];
        Coordinate c{current.coords};
        current.IsVisited = true;
        current.IsFilledRoom = true;

        //loop through possible edges
        //north
        if (current.coords.x != 0 && current.north == nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 25) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y - 1};
                Room north_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    north_room = this->_dungeon[c.x][c.y];
                } else {
                    north_room = *new Room(_roomCount++, c);
                    north_room.IsFilledRoom = true;
                    north_room.IsVisited = true;
                }
                Hall* h = new Hall(current.coords, north_room.coords, 1);
                current.north = h;
                north_room.south = h;
                _rooms.addBack(north_room);
                _dungeon[c.x][c.y] = north_room;
            }
        }

        //south
        if (current.coords.y != _height - 1 && current.south == nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 25) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y + 1};
                Room south_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    south_room = this->_dungeon[c.x][c.y];
                } else {
                    south_room = *new Room(_roomCount++, c);
                    south_room.IsFilledRoom = true;
                    south_room.IsVisited = true;
                }
                Hall* h = new Hall(current.coords, south_room.coords, 1);
                current.south = h;
                south_room.north = h;
                _rooms.addBack(south_room);
                _dungeon[c.x][c.y] = south_room;
            }
        }

        //east
        if (current.coords.x != _width - 1 && current.east == nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 25) {
                //new north coordinate
                Coordinate c{current.coords.x + 1, current.coords.y};
                Room east_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    east_room = this->_dungeon[c.x][c.y];
                } else {
                    east_room = *new Room(_roomCount++, c);
                    east_room.IsFilledRoom = true;
                    east_room.IsVisited = true;
                }
                Hall* h = new Hall(current.coords, east_room.coords, 0);
                current.east = h;
                east_room.west = h;
                _rooms.addBack(east_room);
                _dungeon[c.x][c.y] = east_room;
            }
        }

        //west
        if (current.coords.x != 0 && current.west == nullptr) {
            int rand = r.getRand(0, 100);
            //Make edge if coin toss is true
            if (rand > 25) {
                //new north coordinate
                Coordinate c{current.coords.x - 1, current.coords.y};
                Room west_room;
                //change to abstraction where not everything is default room
                //If room north already exist lay connection with the existing node.
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    west_room = this->_dungeon[c.x][c.y];
                } else {
                    west_room = *new Room(_roomCount++, c);
                    west_room.IsFilledRoom = true;
                    west_room.IsVisited = true;
                }
                Hall* h = new Hall(current.coords, west_room.coords, 0);
                current.west = h;
                west_room.east = h;
                _rooms.addBack(west_room);
                _dungeon[c.x][c.y] = west_room;
            }
        }
        _dungeon[c.x][c.y] = current;
    }
}

void Dungeon::PrintDungeon() {
    for (int i = 0; i < _height; ++i) {
        nostd::Array<Hall> print_halls{_width};
        for (int j = 0; j < _width ; ++j) {
            Room r = this->_dungeon[j][i];
            std::cout << r.GetChar();
            if (r.east != nullptr) {
                std::cout << r.GetChar();
            } else {
                std::cout << ' ';
            }

            if (r.south != nullptr) {
                print_halls.addBack(*r.south);
            } else {
                print_halls.addBack(Hall{});
            }
        }
        std::cout << std::endl;
        for (Hall& h : print_halls) {
            std::cout << h.getChar();
            std::cout << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "done" << std::endl;

//    for (int i = 0; i < _width; ++i) {
//        nostd::Array<Hall> print_halls{_width};
//        for (int j = 0; j < _height; ++j) {
//            std::cout << this->_dungeon[i][j].GetChar();
//            if (this->_dungeon[i][j].east != nullptr) {
//                std::cout << this->_dungeon[i][j].east->getChar();
//            } else {
//                std::cout << ' ';
//            }
//
//            if (this->_dungeon[i][j].south != nullptr) {
//                print_halls.addBack(*this->_dungeon[i][j].south);
//            }
//        }
//        std::cout << std::endl;
//        for (Hall& h : print_halls) {
//            std::cout << h.getChar();
//        }
//        std::cout << std::endl;
//    }
}
