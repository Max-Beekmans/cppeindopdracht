#ifndef EINDOPDRACHT_SAILINGSTATE_H
#define EINDOPDRACHT_SAILINGSTATE_H

#include "BaseState.h"

class SailingState : public BaseState {
public:
    SailingState() = default;
    ~SailingState();
    void Init() override;
    void Update() override;
    StateEnum GetName() override {
        return Sailing;
    };
private:

};

#endif //EINDOPDRACHT_SAILINGSTATE_H
