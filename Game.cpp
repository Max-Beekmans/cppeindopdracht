//
// Created by Martijn Coomans on 28-10-2018.
//

#include <fstream>
#include <iostream>
#include "nostd/String.h"
#include "nostd/IOHandler.h"
#include "nostd/Random.h"
#include "Game.h"
#include "Room.h"

Game::Game() {
    _current_layer = 0;
    _hero = Hero();
    _io = nostd::IOHandler();
    this->_monsters = nostd::Array<Monster>{10};
    this->GetMonsters();
}

Game::~Game() {

}

void Game::Start() {
    std::cout << "Welcome to 'Draken & Kerkers'" << std::endl;

    std::cout << "Please choose a hero name" << std::endl;
    nostd::String hero_name = _io.GetString();
    std::cout << "Please give a width for the dungeon" << std::endl;
    const int width = _io.GetInt();
    std::cout << "Please give a height for the dungeon" << std::endl;
    const int height = _io.GetInt();

    for (int i = 0; i < 5; ++i) {
        _dungeon_layers[i] = Dungeon {width, height, i};
    }

    _hero = Hero{hero_name, _dungeon_layers[4].begin};
    //doturn
    //if opponent
    //  fight()
    _io.Print("current layer ");
    _io.PrintLine(_hero.layer);
    _io.Print("current coords: ");
    _io.Print(_hero.location.x);
    _io.Print(",");
    _io.PrintLine(_hero.location.y);

    Room current = _dungeon_layers[_hero.layer].GetRoom(_hero.location);

    this->EnterRoom(current);
}

void Game::EnterRoom(Room room) {
    nostd::Random r{};
    _io.Print(room.GetDescription());
    Monster* m = nullptr;
    if (r.getRand(0, 100) > 50) {
        m = this->GetMonster(_hero.layer);
    }
    this->GetInput(room, m);
}

void Game::GetInput(Room room, Monster* m) {
    bool done = false;
    while(!done) {
        //Monster* m = room.Monster
        //hardcoded
        //Monster* m = new Monster{nostd::String("Rat"), nostd::String("1"), 20, 1, 1, 2, 20, 1};
        Item* i = room.TakeItem();
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "[ " << (m != nullptr ? "fight | " : "") << "run | rest | items | map | stats | skill | " << (i != nullptr ? "take | " : "") << "quit ]" << std::endl;
        nostd::String input = _io.GetString();


        if (input == nostd::String{"fight"}) {
            if (m != nullptr) {
                this->StartFight(m);
            } else {
                std::cout << "There is no one to fight." << std::endl;
            }
        } else if (input == nostd::String{"run"}) {
            this->Run();
            done = true;
        } else if (input == nostd::String{"rest"}) {
            _hero.Rest();
        } else if (input == nostd::String{"items"}) {
            _hero.PrintBag();
        } else if (input == nostd::String{"map"}) {
            this->PrintMap(_hero.layer);
        } else if (input == nostd::String{"stats"}) {
            _hero.PrintStats();
        } else if(input == nostd::String{"skill"}) {
            _hero.UseSkillPoints();
        }
        else if (input == nostd::String{"take"}) {
            if (i != nullptr) {
                _hero.PickUpItem(i);
            } else {
                std::cout << "There was nothing to take." << std::endl;
            }
        } else if (input == nostd::String{"quit"}) {
            this->Stop();
            done = true;
        }
    }
}

void Game::StartFight(Monster* m) {
    if(m != nullptr) {
        bool fighting = true;
        std::cout << "You encounter " << m->name << "." << std::endl;
        std::cout << m->name << " has " << m->currentHP << " hitpoints." << std::endl;
        while (fighting) {
            if(m->currentHP <= 0){
                if(m->level.c_str() != "BAAS") {
                    _hero.AddExp(m->level.c_str() - "0");
                } else {
                    _hero.AddExp(12);
                }

                fighting = false;
            }

            std::cout << "What would you like to do?" << std::endl;
            std::cout << "[ attack | run | item ]" << std::endl;
            nostd::String input = _io.GetString();

            if(input.c_str() == "attack") {

                //Hero's turn
                int hDamage = m->Block(_hero.Attack());
                std::cout << "You did " << hDamage << "damage." << std::endl;
                std::cout << m->name << " has " << m->currentHP << " hitpoints left." << std::endl;

                //Monster's turn
                int mDamage = _hero.Block(m->Attack());
                std::cout << "You received " << hDamage << "damage." << std::endl;
                std::cout << "You have " << m->currentHP << " hitpoints left." << std::endl;
            } else if(input.c_str() == "run") {
                this->Run();
                fighting = false;
            } else if(input.c_str() == "item") {
                for(int i = 0; i < _hero.Item_bag.size(); i++) {
                    std::cout << "[" << i << "] " << _hero.Item_bag.at(i).name;
                }
                std::cout << "What item do you want to use? (enter number)" << std::endl;
                int index = _io.GetInt();

                if(index <_hero.Item_bag.size() - 1) {
                    if(_hero.Item_bag.at(index).uses > 0) {
                        _hero.UseItem(_hero.Item_bag.at(index));
                        _hero.Item_bag.at(index).uses--;
                    } else {
                        std::cout << "That item has no uses left";
                    }
                }
            }
        }
    }
}

void Game::Run() {
    std::cout << "In what direction would you like to run?" << std::endl;
    nostd::String direction = _io.GetString();

    if(direction.c_str() == "north") {
        _hero.Move('N');
    } else if(direction.c_str() == "south") {
        _hero.Move('S');
    } else if(direction.c_str() == "west") {
        _hero.Move('W');
    } else if(direction.c_str() == "east") {
        _hero.Move('E');
    } else {
        this->Run();
    }

    EnterRoom(_dungeon_layers[_hero.layer].GetRoom(_hero.location));
}

void Game::Stop() {
    //clean up global memory or anything not being freed with going out of scope.

}

void Game::GetMonsters() {
    std::ifstream fileStream;
    char line[14][512];
    //todo: exception handling
    fileStream.open("monsters.txt");
    bool isopen = fileStream.is_open();
    int i = 0;
    while (!fileStream.eof()) {
        fileStream.getline(line[i], sizeof(line[i]));
        if (line[i][0] == '[') {
            nostd::String strings[6];
            //nostd::Array<nostd::String> strings{6};
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
                        strings[c] += line[i][j];
                        break;
                }
                j++;
            }

            char* first = nullptr;
            char* second = nullptr;

            nostd::String name = strings[0];
            nostd::String level = strings[1];

            nostd::String* ac_res = strings[2].Split('x');
            first = ac_res[0].c_str();
            second = ac_res[1].c_str();

            int attackChance = std::atoi(first);
            int attackAmount = std::atoi(second);

            nostd::String* minmax_res = strings[3].Split('-');
            first = minmax_res[0].c_str();
            second = minmax_res[1].c_str();

            int minDamage = std::atoi(first);
            int maxDamage = std::atoi(second);

            first = strings[4].c_str();
            second = strings[5].c_str();
            int defenceChance = std::atoi(first);
            int maxHP = std::atoi(second);

            _monsters[i] = Monster(name, level, attackChance, attackAmount, minDamage, maxDamage, defenceChance, maxHP);
            i++;
        }
    }
    fileStream.close();
}

//print given dungeon layer
void Game::PrintMap(const int layer) {
    this->PrintDivider();
    std::cout << "Dungeon Map" << std::endl;
    std::cout << "Layer: " << layer << std::endl;
    _dungeon_layers[layer].PrintDungeon();
    this->PrintLegend();
    this->PrintDivider();
}

//if invalid x = -1 else x = int user input
int Game::GetInt() {
    int x = -1;
    std::cin >> x;
    return x;
}

//Get char* from user input, copies that into str and wraps that into nostd::String
nostd::String Game::GetString() {
    char* str = new char[80];
    std::cin >> str;
    return nostd::String {str};
}

//Print 10 empty lines to the console
void Game::ClearConsole() {
    for (int i = 0; i < 10; ++i) {
        std::cout << '\n';
    }
    std::cout << std::endl;
}

//Print sipmle underscore divider
void Game::PrintDivider() {
    std::cout << std::endl << "_____________________________________________" << std::endl;
}

void Game::PrintLegend() {
    std::cout << "Legend: " << std::endl;
    std::cout << "-| : Hallways" << std::endl;
    std::cout << "S  : Start location" << std::endl;
    std::cout << "E  : Final boss room" << std::endl;
    std::cout << "N  : Regular room" << std::endl;
    std::cout << "L  : Stair down" << std::endl;
    std::cout << "H  : Stair up" << std::endl;
    std::cout << ".  : Not visited / doesn't exist" << std::endl;
}

Monster* Game::GetMonster(const int layer) {
    //get all monsters with given layer
    Monster* temp[3];
    nostd::Random rand;
    char c = static_cast<char>(layer);
    char* cc = &c;
    nostd::String level {cc};
    int count = 0;
    for (int i = 0; i < _monsters.size(); ++i) {
        if (_monsters[i].level == level) {
            temp[count] = &_monsters[i];
            count++;
        }
    }

    int r = rand.getRand(0, count);
    return temp[r];
}
