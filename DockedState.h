#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"

class DockedState : public BaseState {
public:
    DockedState(Player* player, StateManager* stateManager);
    ~DockedState();
    void Update() override;
    StateEnum GetName() override {
        return Docked;
    };
private:
    void print_options();
};

#endif //EINDOPDRACHT_DOCKEDSTATE_H
