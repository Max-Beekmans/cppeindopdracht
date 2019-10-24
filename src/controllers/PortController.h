#ifndef EINDOPDRACHT_PORTCONTROLLER_H
#define EINDOPDRACHT_PORTCONTROLLER_H

#include "../nostd/Array.h"
#include <string>
#include "GameController.h"
#include "../models/Port.h"
namespace controllers {

    class PortController {
    public:
        PortController(GameController& game);

        ~PortController() = default;

    private:
        models::Port _current_port;

        void BuyCargo();

        bool SellCargo();

        void BuyCannons();

        bool SellCannons();

        void SailTo();

        bool BuyShip();

        void ShowGoldBalance();

        void ShowShipHealth();

        void RepairShip();
    };
}
#endif //EINDOPDRACHT_PORTCONTROLLER_H
