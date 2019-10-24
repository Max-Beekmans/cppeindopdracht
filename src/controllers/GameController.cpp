//
// Created by MaxBe on 09-Jan-19.
//

#include "../factories/PortFactory.h"
#include "../factories/ShipFactory.h"
#include "../exceptions/PortNotFoundException.h"

#include "GameController.h"
#include "../models/Cannon.h"

controllers::GameController::GameController() : _gold(0), _view(new views::GameView()), _port(new PortController(*this)) {}

void controllers::GameController::StartGame() {
    _view->PrintIntroduction();
    factories::ShipFactory sf;
    _ship = sf.CreateRandomShip();
    _destinationPort = nostd::String{"Port Royale"};

    //TODO remove test line
    _ship.AddCannon(models::Cannon{1, 0, 25});

    EnterPort();
}

void controllers::GameController::EnterPort() {
    _port->Enter(_destinationPort);
}

void GameController::StartFight() {
    _fight->Start();
}

void GameController::Sail(const int turns) {
    _sea->Sail(turns);
}

controllers::GameController::~GameController() {
    delete _view;
    delete _port;
    delete _fight;
    delete _sea;
}
