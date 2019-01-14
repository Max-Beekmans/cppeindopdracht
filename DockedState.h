#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"
#include "StateManager.h"

class DockedState : public BaseState {
public:
    DockedState(Player& player, StateManager& stateManager);
    ~DockedState();
    bool Update() override;
    StateEnum GetName() override {
        return Docked;
    };
private:
    Port _current_port;
    Ship& _player_ship;
    void BuyCargo();
    void SellCargo();
    void BuyCannons();
    void SellCannons();
    void SailTo();
    void BuyShip();
    void ShowGoldBalance();
    void ShowShipHealth();
    void RepairShip();
};

#endif //EINDOPDRACHT_DOCKEDSTATE_H
