#ifndef EINDOPDRACHT_SAILINGSTATE_H
#define EINDOPDRACHT_SAILINGSTATE_H

#include "nostd/BaseState.h"

class SailingState : public nostd::BaseState {
public:
    SailingState() = default;
    void Init() override;
    void Update() override;
    void Pause() override;
    void Resume() override;
    void Cleanup() override;
    StateEnum GetName() override {
        return Sailing;
    };
private:

};

#endif //EINDOPDRACHT_SAILINGSTATE_H
