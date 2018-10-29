//
// Created by Martijn Coomans on 28-10-2018.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    _running = false;
    _dungeon = nullptr;
}

Game::~Game() {

}

void Game::Update() {
    while(_running) {
        std::cout << "Generated Dungeon";
        _dungeon->PrintDungeon();
    }
}

void Game::Start() {
    _running = true;
    this->CreateDungeon(5, 5);
    this->Update();
}

void Game::Stop() {
    _running = false;
}

void Game::CreateDungeon(int width, int height){
    _dungeon = new Dungeon(width, height);
    _dungeon->GenerateDungeon();
}