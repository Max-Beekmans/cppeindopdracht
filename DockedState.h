#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"

class DockedState : public BaseState {
public:
    DockedState(Player& player, StateManager& stateManager);
    ~DockedState();
    void Update() override;
    StateEnum GetName() override {
        return Docked;
    };
protected:
    void print_options() override;
private:
    Port& _current_port;
    Ship& _player_ship;
    void BuyCargo();
    void SellCargo();
    void BuyCannons();
    void SellCannons();
    void BuyShip();
    void ShowGoldBalance();
    void ShowShipHealth();
    void RepairShip();
};

#endif //EINDOPDRACHT_DOCKEDSTATE_H
