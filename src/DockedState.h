#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"
#include "StateManager.h"

class DockedState : public BaseState {
public:
    DockedState(Player& player, StateManager& stateManager);
    ~DockedState() = default;
    bool Update() override;
private:
    Port _current_port;
    Ship& _player_ship;
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

#endif //EINDOPDRACHT_DOCKEDSTATE_H
