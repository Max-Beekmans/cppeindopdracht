#ifndef EINDOPDRACHT_PORTCONTROLLER_H
#define EINDOPDRACHT_PORTCONTROLLER_H

#include "nostd/Array.h"
#include "nostd/String.h"
#include "GameController.h"

class PortController {
public:
    PortController(GameController& game);
    ~PortController() = default;
private:
    Port _current_port;
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

#endif //EINDOPDRACHT_PORTCONTROLLER_H
