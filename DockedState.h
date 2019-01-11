#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"

class DockedState : public BaseState {
public:
    DockedState() = default;
    ~DockedState();
    void Init() override;
    void Update() override;
    StateEnum GetName() override {
        return Docked;
    };
private:

};

#endif //EINDOPDRACHT_DOCKEDSTATE_H
