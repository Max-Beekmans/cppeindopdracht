#ifndef EINDOPDRACHT_SAILINGSTATE_H
#define EINDOPDRACHT_SAILINGSTATE_H

#include "BaseState.h"
#include "Port.h"
#include "StateManager.h"

class SailingState : public BaseState {
public:
    SailingState(Player& player, StateManager& stateManager, const int turns);
    ~SailingState();
    bool Update() override;
    int CalculateTurns(const Port& currentPort, const Port& destinationPort);
    StateEnum GetName() override {
        return Sailing;
    };
private:
    int _turns;
};

#endif //EINDOPDRACHT_SAILINGSTATE_H
