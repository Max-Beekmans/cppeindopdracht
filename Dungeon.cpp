 //
// Created by MaxBe on 10/22/2018.
//

#include <iostream>
#include <fstream>
#include "Dungeon.h"
#include "Hall.h"
#include "Room.h"
#include "Monster.h"
#include "nostd/Random.h"
#include "nostd/String.h"
#include "nostd/Array.h"

Dungeon::Dungeon(const int width, const int height) : _width(width), _height(height) {
    this->_dungeon = new Room*[width];
    for(int i = 0; i < width; ++i) {
        this->_dungeon[i] = new Room[height];
    }
    this->_roomCount = 0;
    this->_monsters = nostd::Array<Monster>{10};
    this->GetMonsters();
}

void Dungeon::GetMonsters() {
    std::ifstream fileStream;
    char line[14][512];
    //todo: exception handling
    fileStream.open("monsters.txt");
    bool isopen = fileStream.is_open();
    int i = 0;
    while(!fileStream.eof()){
        fileStream.getline(line[i], sizeof(line[i]));
        if(line[i][0] == '['){
            nostd::Array<nostd::String> strings{6};
            int c = 0;
            int j = 1;
            bool reading = true;
            while(reading)
            {
                switch(line[i][j]) {
                    case ';':
                        c++;
                        break;
                    case ']':
                        reading = false;
                        break;
                    default:
                        nostd::String temp = strings[c];
                        temp += line[i][j];
                        strings[c] = temp;
                        break;
                }
                j++;
            }

            nostd::String name = strings[0];
            nostd::String level = strings[1];

            int attackChance = static_cast<int>(strings[2].c_str()[0]);
            int attackAmount = static_cast<int>(strings[2].c_str()[2]);
            int minDamage= static_cast<int>(strings[3].c_str()[0]);
            int maxDamage= static_cast<int>(strings[3].c_str()[2]);
            int defenceChance= static_cast<int>(strings[4].c_str()[2]);
            int maxHP= static_cast<int>(strings[5].c_str()[2]);

            _monsters[i] = Monster(name, level, attackChance, attackAmount, minDamage, maxDamage, defenceChance, maxHP);
            i++;
        }
    }
    fileStream.close();
    this->PrintDungeon();
}

void Dungeon::GenerateDungeon() {
    Monster m = _monsters[0];
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
            if (rand > 20) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y - 1};
                Room north_room;
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
            if (rand > 20) {
                //new north coordinate
                Coordinate c{current.coords.x, current.coords.y + 1};
                Room south_room;
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
                std::cout << r.east->GetChar();
            } else {
                std::cout << ' ';
            }

            if (r.south != nullptr) {
                print_halls.addBack(*r.south);
            } else {
                Hall h;
                print_halls.addBack(h);
            }
        }
        std::cout << std::endl;
        for (Hall& h : print_halls) {
            std::cout << h.GetChar();
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
