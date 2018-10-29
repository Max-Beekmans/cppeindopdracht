//
// Created by Martijn Coomans on 28-10-2018.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    _current_layer = 0;
}

Game::~Game() {

}

void Game::Update() {}

void Game::Start() {
    std::cout << "Welcome to 'Draken & Kerkers'" << std::endl;
    std::cout << "Please give a width for the dungeon" << std::endl;
    const int width = GetInt();
    std::cout << "Please give a height for the dungeon" << std::endl;
    const int height = GetInt();

    //temp I'll make this prettier to the point where you only need to call what is given in the game constructor
    //TODO make copy and move for dungeon D:
    _dungeon_layers[_current_layer] = *new Dungeon {width, height, _current_layer};
    this->PrintMap();
}

void Game::Stop() {
    //clean up global memory or anything not being freed with going out of scope.
}

//prints current dungeon layer once
void Game::PrintMap() {
    _dungeon_layers[_current_layer].PrintDungeon();
}

//if invalid x = -1 else x = int user input
int Game::GetInt() {
    int x = -1;
    std::cin >> x;
    return x;
}

//Get char* from user input, copies that into string and returns that
nostd::String Game::GetString() {
    char* str = nullptr;
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
