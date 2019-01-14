#ifndef EINDOPDRACHT_SAILINGSTATE_H
#define EINDOPDRACHT_SAILINGSTATE_H

#include "BaseState.h"
#include "StateManager.h"
#include "Port.h"

class SailingState : public BaseState {
public:
    SailingState(Player& player, StateManager& stateManager, const int turns);
    ~SailingState() = default;
    bool Update() override;
private:
    int _turns;
};

#endif //EINDOPDRACHT_SAILINGSTATE_H
