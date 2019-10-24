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

void Game::StartGame() {
//    io.PrintLine("Start game");
//    PrintIntroduction();
    factory::ShipFactory sf;
    Ship starting_ship = sf.CreateRandomShip();

    //TODO remove test line
    starting_ship.AddCannon(Cannon{1, 0, 25});

    StateManager stateManager{};
    Player player{starting_ship, nostd::String{"Port Royale"}};

    stateManager.PushState(new DockedState(player, stateManager));

    //loops until some state returns false. Exit the game if false;
    while(stateManager.CurrentState()->Update()) {}
    io.PrintLine("Quit game");
}
