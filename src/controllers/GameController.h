//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_GAMECONTROLLER_H
#define EINDOPDRACHT_GAMECONTROLLER_H

#include "nostd/IOHandler.h"
#include "../models/Player.h"
#include "../views/GameView.h"
#include "../controllers/SailingController.h"
#include "../controllers/FightingController.h"
#include "../controllers/PortController.h"

namespace controllers {

    class GameController {
    public:
        GameController();

        ~GameController();

        void StartGame();

        void EnterPort(const std::String name);
        void StartBattle();
        void Sail();

        void ReceiveGold(int gold) {
            _gold += gold;
        }

        void LoseGold(int gold) {
            _gold -= gold;
        }

        const int GetGold() {
            return _gold;
        }

        Ship &GetShip() {
            return _ship;
        }

        void SetShip(Ship ship) {
            _ship = ship;
        }

        const nostd::String GetDestinationPort() {
            return _destinationPort;
        }

        void SetDestinationPort(const nostd::String port) {
            _destinationPort = port;
        }

    private:
        nostd::IOHandler io;
        nostd::string _destinationPort;
        int _gold;
        Ship* _ship;
        GameView* _view;
        PortController* _port;
        SailingController* _sea;
        FightingController* _fight;
    };

}
#endif //EINDOPDRACHT_GAMECONTROLLER_H
