//
// Created by Martijn Coomans on 28-10-2018.
//

#include "Game.h"
#include <iostream>
#include "nostd/String.h"

Game::Game() {
    _current_layer = 0;
    _hero = Hero();
}

Game::~Game() {

}

void Game::Update() {}

void Game::Start() {
    std::cout << "Welcome to 'Draken & Kerkers'" << std::endl;

    std::cout << "Please choose a hero name" << std::endl;
    _hero = Hero{GetString()};
    std::cout << "Please give a width for the dungeon" << std::endl;
    const int width = GetInt();
    std::cout << "Please give a height for the dungeon" << std::endl;
    const int height = GetInt();

    //temp I'll make this prettier to the point where you only need to call what is given in the game constructor
    //TODO make copy and move for dungeon D:

    this->PrintHeroStats();
    this->PrintDivider();

    _dungeon_layers[_current_layer] = Dungeon {width, height, _current_layer};
    _current_layer++;
    _dungeon_layers[_current_layer] = Dungeon {width, height, _current_layer};
    this->PrintMap(0);
    this->PrintMap(1);
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
