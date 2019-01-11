#ifndef EINDOPDRACHT_FIGHTINGSTATE_H
#define EINDOPDRACHT_FIGHTINGSTATE_H

#include "BaseState.h"

class FightingState : public BaseState {
public:
    FightingState() = default;
    ~FightingState();
    void Init() override;
    void Update() override;
    StateEnum GetName() override {
        return Fighting;
    };
private:

};

#endif //EINDOPDRACHT_FIGHTINGSTATE_H
