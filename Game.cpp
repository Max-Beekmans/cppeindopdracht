//
// Created by MaxBe on 09-Jan-19.
//

#include "Game.h"
#include "Factory/PortFactory.h"
#include "exceptions/PortNotFoundException.h"

#include "StateManager.h"
#include "Player.h"
#include "SailingState.h"
#include "FightingState.h"
#include "DockedState.h"

Game::Game() {

}

Game::~Game() {

}

void Game::StartGame() {
    /*io.PrintLine("Start game");
    PrintIntroduction();
    factory::PortFactory pf;
    try{
        _current_port = pf.CreatePort(nostd::String{"Roatan"});
        _current_port->PrintValues();
    } catch (exceptions::PortNotFoundException &e) {
        io.PrintLine(e.what());
    }*/

    StateManager* stateManager;
    Player* player;

    stateManager->PushState(new FightingState(player, stateManager));
    stateManager->PushState(new DockedState(player, stateManager));
    stateManager->PushState(new SailingState(player, stateManager));
}

void Game::PrintIntroduction() {
    io.PrintLine("Introduction");
}
