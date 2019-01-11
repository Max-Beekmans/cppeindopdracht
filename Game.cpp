//
// Created by MaxBe on 09-Jan-19.
//

#include "Game.h"
#include "PortFactory.h"
#include "exceptions/PortNotFoundException.h"

Game::Game() {

}

Game::~Game() {

}

void Game::StartGame() {
    io.PrintLine("Start game");
    PrintIntroduction();
    PortFactory pf;
    try{
        current_port = pf.CreatePort(nostd::String{"Roatan"});
        current_port->PrintValues();
    } catch (PortNotFoundException &e) {
        io.PrintLine(e.what());
    }
}

void Game::PrintIntroduction() {
    io.PrintLine("Introduction");
}
