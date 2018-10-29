//
// Created by MaxBe on 10/22/2018.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Dungeon.h"
#include "Hall.h"
#include "Room.h"
#include "Monster.h"
#include "nostd/Random.h"
#include "nostd/String.h"
#include "nostd/Array.h"

Dungeon::Dungeon() : _width(-1), _height(-1), _roomCount(-1), _begin(nullptr), _level(-1) {}

Dungeon::Dungeon(const int width, const int height, const int level)
        : _width(width), _height(height), _level(level), _roomCount(0) {
    this->_dungeon = nostd::Array<Room*>{_height};
    for (int i = 0; i < _height; ++i) {
        this->_dungeon[i] = new Room[_width];
    }

    this->GenerateDungeon();

    //TODO build up array somewhere different but have dungeon access it instead
    //TODO include this into room builder dungeon doesn't need to know about monsters. the room does
    //dungeon can copy from the monster array
    this->_monsters = nostd::Array<Monster>{10};
    this->GetMonsters();
}

//clean up dungeon matrix. Rest of the vars are stack allocations
Dungeon::~Dungeon() {
    //not sure about _begin
    delete _begin;
}

Dungeon::Dungeon(const Dungeon &copy) : _width(copy._width), _height(copy._height) {
    copy_from(copy);
}

Dungeon::Dungeon(Dungeon &&move) noexcept : _width(move._width), _height(move._height) {
    move_from(move);
}

Dungeon &Dungeon::operator=(const Dungeon &copy) {
    if (this == &copy) return *this;
    copy_from(copy);
    return *this;
}

Dungeon &Dungeon::operator=(Dungeon &&move) noexcept {
    if (this == &move) return *this;
    move_from(move);
    return *this;
}

void Dungeon::GetMonsters() {
    std::ifstream fileStream;
    char line[14][512];
    //todo: exception handling
    fileStream.open("monsters.txt");
    bool isopen = fileStream.is_open();
    int i = 0;
    while (!fileStream.eof()) {
        fileStream.getline(line[i], sizeof(line[i]));
        if (line[i][0] == '[') {
            nostd::Array<nostd::String> strings{6};
            int c = 0;
            int j = 1;
            bool reading = true;
            while (reading) {
                switch (line[i][j]) {
                    case ';':
                        c++;
                        break;
                    case ']':
                        reading = false;
                        break;
                    default:
                        strings.at(c) += line[i][j];
                        break;
                }
                j++;
            }
            int attackChance = std::atoi(strings[2].c_str());
            //make into atoi
            //int attackChance = static_cast<int>(strings[2][0]);
            int attackAmount = static_cast<int>(strings[2][2]);
            int minDamage = static_cast<int>(strings[3][0]);
            int maxDamage = static_cast<int>(strings[3][2]);
            int defenceChance = static_cast<int>(strings[4][2]);
            int maxHP = static_cast<int>(strings[5][2]);
            nostd::String name = strings.at(1);
            nostd::String level = strings.at(2);

            _monsters[i] = Monster(name, level, attackChance, attackAmount, minDamage, maxDamage, defenceChance, maxHP);
            i++;
        }
    }
    fileStream.close();
}

void Dungeon::GenerateDungeon() {
    Monster m = _monsters[0];
    nostd::Random r{};
    int max = (_width * _height);
    int count = 0;
    this->_rooms = nostd::Array<Room*>(max);
    this->_halls = nostd::Array<Hall>(max * 2);

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
    this->_rooms.addBack(this->_begin);

    while (_roomCount < max) {
        //this boolean should be set for all 'build' rooms.
        // We don't want to visit default constructable rooms
        if (_rooms[count] == nullptr || !_rooms[count]->IsFilledRoom) {
            break;
        }
        Room* current = _rooms[count++];
        current->IsVisited = true;
        current->IsFilledRoom = true;

        //loop through possible edges
        //north
        if (current->coords.x != 0 && _roomCount <= max) {
            int rand = r.getRand(0, 100);
            if (rand > 25) {
                Coordinate c{current->coords.x, current->coords.y - 1};
                Room* north_room;
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    north_room = &this->_dungeon[c.x][c.y];
                } else {
                    north_room = new Room(_roomCount++, c);
                }
                Hall h = Hall{current->coords, c, 1};
                current->north = h;
                north_room->south = h;
                this->_rooms.addBack(north_room);
                this->_dungeon[c.x][c.y] = *north_room;
            }
        }

        //south
        if (current->coords.y != _height - 1 && _roomCount <= max) {
            int rand = r.getRand(0, 100);
            if (rand > 25) {
                Coordinate c{current->coords.x, current->coords.y + 1};
                Room* south_room;
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    south_room = &this->_dungeon[c.x][c.y];
                } else {
                    south_room = new Room(_roomCount++, c);
                }
                Hall h = Hall{current->coords, c, 1};
                current->south = h;
                south_room->north = h;
                this->_rooms.addBack(south_room);
                this->_dungeon[c.x][c.y] = *south_room;
            }
        }

        //east
        if (current->coords.x != _width - 1 && _roomCount <= max) {
            int rand = r.getRand(0, 100);
            if (rand > 25) {
                Coordinate c{current->coords.x + 1, current->coords.y};
                Room* east_room;
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    east_room = &this->_dungeon[c.x][c.y];
                } else {
                    east_room = new Room(_roomCount++, c);
                }
                Hall h = Hall{current->coords, c, 0};
                current->east = h;
                east_room->west = h;
                this->_rooms.addBack(east_room);
                this->_dungeon[c.x][c.y] = *east_room;
            }
        }

        //west
        if (current->coords.x != 0 && _roomCount <= max) {
            int rand = r.getRand(0, 100);
            if (rand > 25) {
                Coordinate c{current->coords.x - 1, current->coords.y};
                Room* west_room;
                if (this->_dungeon[c.x][c.y].IsFilledRoom) {
                    west_room = &this->_dungeon[c.x][c.y];
                } else {
                    west_room = new Room(_roomCount++, c);
                }
                Hall h = Hall{current->coords, c, 0};
                current->west = h;
                west_room->east = h;
                this->_rooms.addBack(west_room);
                this->_dungeon[c.x][c.y] = *west_room;
            }
        }
        _dungeon[current->coords.x][current->coords.y] = *current;
    }
    this->SetStairs(_level);
}

void Dungeon::PrintDungeon() {
    for (int i = 0; i < _height; ++i) {
        nostd::Array<Hall> print_halls{_width};
        for (int j = 0; j < _width; ++j) {
            Room r = this->_dungeon[j][i];
            std::cout << r.GetChar();
            if (r.IsFilledRoom) {
                std::cout << r.east.GetChar();
            } else {
                std::cout << ' ';
            }

            if (r.IsFilledRoom) {
                print_halls.addBack(r.south);
            } else {
                Hall h;
                print_halls.addBack(h);
            }
        }
        std::cout << std::endl;
        for (Hall &h : print_halls) {
            std::cout << h.GetChar();
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

void Dungeon::copy_from(const Dungeon &copy) {
    this->_dungeon = copy._dungeon;
    this->_level = copy._level;
    this->_roomCount = copy._roomCount;
    this->_rooms = copy._rooms;
    this->_halls = copy._halls;
    this->_width = copy._width;
    this->_height = copy._height;
}

void Dungeon::move_from(Dungeon &move) {
    this->_dungeon = move._dungeon;
    this->_level = move._level;
    this->_roomCount = move._roomCount;
    this->_rooms = move._rooms;
    this->_halls = move._halls;
    this->_width = move._width;
    this->_height = move._height;
}

void Dungeon::SetStairs(const int layer) {
    nostd::Random r{};
    int x = r.getRand(0, _width);
    int y = r.getRand(0, _height);

    //Don't generate stair up for top room
    if (layer < 5) {
        while (!_dungeon[x][y].IsFilledRoom || _dungeon[x][y].IsStart || _dungeon[x][y].IsEndBoss || _dungeon[x][y].IsStairDown) {
            x = r.getRand(0, _width);
            y = r.getRand(0, _height);
        }
        _dungeon[x][y].IsStairUp = true;
    }

    //Don't generate stair down for bottom room
    if (layer > 0) {
        while (_dungeon[x][y].IsFilledRoom || _dungeon[x][y].IsStart || _dungeon[x][y].IsEndBoss || _dungeon[x][y].IsStairUp) {
            x = r.getRand(0, _width);
            y = r.getRand(0, _height);
        }
        _dungeon[x][y].IsStairDown = true;
    }
}

Room Dungeon::GetRoom(const int x, const int y) {
    if (x > _width || x < 0 || y > _height || y < 0) {
        throw std::out_of_range("x or y out of range");
    }
    Room r = this->_dungeon[x][y];
    return r;
}
