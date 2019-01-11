#ifndef EINDOPDRACHT_SAILINGSTATE_H
#define EINDOPDRACHT_SAILINGSTATE_H

#include "BaseState.h"

class SailingState : public BaseState {
public:
    SailingState(Player* player, StateManager* stateManager);
    ~SailingState();
    void Update() override;
    StateEnum GetName() override {
        return Sailing;
    };
};

#endif //EINDOPDRACHT_SAILINGSTATE_H
