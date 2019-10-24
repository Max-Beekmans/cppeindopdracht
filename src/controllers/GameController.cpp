//
// Created by MaxBe on 09-Jan-19.
//

#include "../factories/PortFactory.h"
#include "../factories/ShipFactory.h"
#include "../exceptions/PortNotFoundException.h"

#include "GameController.h"

GameController::GameController() : _gold(0), _view(new GameView()), _port(new PortController(*this)), _fight(new FightingController(*this), _sea(new SailingController(*this))) {}

void GameController::StartGame() {
    view.PrintIntroduction();
    /*factory::ShipFactory sf;
    _ship = sf.CreateRandomShip();
    _destinationPort = nostd::String{"Port Royale"};

    //TODO remove test line
    _ship.AddCannon(Cannon{1, 0, 25});

    EnterPort();*/
}

void GameController::EnterPort() {
    _port->Enter(_destinationPort);
}

void GameController::StartFight() {
    _fight->Start();
}

void GameController::Sail(const int turns) {
    _sea->Sail(turns);
}

GameController::~GameController() {
    delete _view;
    delete _port;
    delete _fight;
    delete _sea;
}
