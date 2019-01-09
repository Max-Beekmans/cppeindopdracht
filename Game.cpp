//
// Created by MaxBe on 09-Jan-19.
//

#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::StartGame() {
    io.PrintLine("Start game");
    PrintIntroduction();

}

void Game::PrintIntroduction() {
    io.PrintLine("Introduction");
}
