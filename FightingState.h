#ifndef EINDOPDRACHT_FIGHTINGSTATE_H
#define EINDOPDRACHT_FIGHTINGSTATE_H

#include "BaseState.h"

class FightingState : public BaseState {
public:
    FightingState() = default;
    void Init() override;
    void Update() override;
    void Pause() override;
    void Resume() override;
    void Cleanup() override;
    StateEnum GetName() override {
        return Fighting;
    };
private:

};

#endif //EINDOPDRACHT_FIGHTINGSTATE_H