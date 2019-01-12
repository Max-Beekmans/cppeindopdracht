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
#include "Factory/ShipFactory.h"

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
    factory::ShipFactory shipFactory;
    StateManager* stateManager = new StateManager();
    Player* player = new Player();
    player->SetShip(shipFactory.CreateRandomShip());
    io.PrintLine(player->GetShip());
    io.PrintLine(player->GetShip().GetCurrentHp());
    player->GetShip().ReceiveDamage(30);
    io.PrintLine(player->GetShip().GetCurrentHp());
    io.PrintLine(player->GetShip());

    //stateManager->PushState(new SailingState(player, stateManager));
    //stateManager->CurrentState()->Update();
}

void Game::PrintIntroduction() {
    io.PrintLine("Introduction");
}
