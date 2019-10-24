//
// Created by MaxBe on 09-Jan-19.
//

#include "../factories/PortFactory.h"
#include "../factories/ShipFactory.h"
#include "../exceptions/PortNotFoundException.h"

#include "GameController.h"

controllers::GameController::GameController() : _gold(0), _view(new views::GameView()) {}

void controllers::GameController::StartGame() {
    _view->PrintIntroduction();
    /*factory::ShipFactory sf;
    _ship = sf.CreateRandomShip();
    _destinationPort = std::string{"Port Royale"};

    //TODO remove test line
    _ship.AddCannon(Cannon{1, 0, 25});

    EnterPort();*/
}

/*void controllers::GameController::EnterPort() {
    _port->Enter(_destinationPort);
}

void GameController::StartFight() {
    _fight->Start();
}

void GameController::Sail(const int turns) {
    _sea->Sail(turns);
}*/

controllers::GameController::~GameController() {
    delete _view;
    /*delete _port;
    delete _fight;
    delete _sea;*/
}
