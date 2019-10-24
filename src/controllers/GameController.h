#ifndef EINDOPDRACHT_GAMECONTROLLER_H
#define EINDOPDRACHT_GAMECONTROLLER_H

#include "../nostd/IOHandler.h"
#include "../views/GameView.h"
#include "../models/Ship.h"
/*#include "../controllers/SailingController.h"
#include "../controllers/FightingController.h"
#include "../controllers/PortController.h"*/

namespace controllers {
    class GameController {
        public:
            GameController();

            ~GameController();

            void StartGame();

            void EnterPort(const nostd::String name);
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

            models::Ship &GetShip() const {
                return *_ship;
            }

            void SetShip(models::Ship ship) {
                _ship = &ship;
            }

            const nostd::String GetDestinationPort() {
                return _destinationPort;
            }

            void SetDestinationPort(const nostd::String port) {
                _destinationPort = port;
            }

        private:
            nostd::IOHandler io;
            nostd::String _destinationPort;
            int _gold;
            models::Ship* _ship;
            views::GameView* _view;
            /*PortController* _port;
            SailingController* _sea;
            FightingController* _fight;*/
    };

}
#endif //EINDOPDRACHT_GAMECONTROLLER_H
