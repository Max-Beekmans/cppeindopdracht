//
// Created by MaxBe on 09-Jan-19.
//

#include "Factory/PortFactory.h"
#include "Factory/ShipFactory.h"
#include "exceptions/PortNotFoundException.h"

#include "Game.h"
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
//    io.PrintLine("Start game");
//    PrintIntroduction();
//    factory::PortFactory pf;
//    try{
//        _current_port = pf.CreatePort(nostd::String{"Roatan"});
//        _current_port->PrintValues();
//    } catch (exceptions::PortNotFoundException &e) {
//        io.PrintLine(e.what());
//    }
//
    factory::PortFactory pf;
    Port starting_port = pf.CreatePort(nostd::String{"Port Royale"});
    factory::ShipFactory sf;
    Ship starting_ship = sf.CreateRandomShip();
    starting_ship.AddCargo(Cargo{nostd::String{"bakstenen"}, 20, 2});

    StateManager stateManager{};
    Player player{starting_ship, starting_port};

    stateManager.PushState(new FightingState(player, stateManager));
    stateManager.PushState(new SailingState(player, stateManager));
    stateManager.PushState(new DockedState(player, stateManager));

    while(stateManager.CurrentState()->Update()) {

    }
    io.PrintLine("Quit game");
}

void Game::PrintIntroduction() {
    io.PrintLine("Introduction");
}
