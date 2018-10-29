//
// Created by Martijn Coomans on 28-10-2018.
//

#include "Game.h"
#include <iostream>
#include "nostd/String.h"
#include "nostd/IOHandler.h"

Game::Game() {
    _current_layer = 0;
    _hero = Hero();
    _io = nostd::IOHandler();
}

Game::~Game() {

}

void Game::Update() {}

void Game::Start() {
    std::cout << "Welcome to 'Draken & Kerkers'" << std::endl;

    std::cout << "Please choose a hero name" << std::endl;
    _hero = Hero{_io.GetString()};
    std::cout << "Please give a width for the dungeon" << std::endl;
    const int width = _io.GetInt();
    std::cout << "Please give a height for the dungeon" << std::endl;
    const int height = _io.GetInt();

    //temp I'll make this prettier to the point where you only need to call what is given in the game constructor
    //TODO make copy and move for dungeon D:

    this->PrintHeroStats();
    this->PrintDivider();

    for (int i = 0; i < 5; ++i) {
        _dungeon_layers[i] = Dungeon {width, height, i};
    }

    for (int j = 0; j < 5; ++j) {
        this->PrintMap(j);
    }
}

void Game::StartFight() {
    //pseudocode nog

    /*Monster m = _dungeon_layers[_current_layer].GetRoom(_hero.location.x, _hero.location.y).Monster;
    bool fighting = true;
    std::cout << "You encounter " << m.name << "." << std::endl;
    std::cout << m.name << " has " << m.currentHP << " hitpoints." << std::endl;
    while (fighting) {
        if(m.currentHP <= 0){
            if(m.level.c_str() != "BAAS") {
                _hero.AddExp(m.level.c_str() - "0");
            } else {
                _hero.AddExp(12);
            }

            fighting = false;
        }

        std::cout << "What would you like to do?" << std::endl;
        nostd::String input = _io.GetString();

        if(input.c_str() == "attack") {

            //Hero's turn
            int hDamage = m.Block(_hero.Attack());
            std::cout << "You did " << hDamage << "damage." << std::endl;
            std::cout << m.name << " has " << m.currentHP << " hitpoints left." << std::endl;

            //Monster's turn
            int mDamage = _hero.Block(m.Attack());
            std::cout << "You received " << hDamage << "damage." << std::endl;
            std::cout << "You have " << m.currentHP << " hitpoints left." << std::endl;
        } else if(input.c_str() == "run") {
            this->Run();
        }
    }*/
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
}

void Game::Stop() {
    //clean up global memory or anything not being freed with going out of scope.
}

void Game::PrintHeroStats() {

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
