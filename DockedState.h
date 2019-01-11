#ifndef EINDOPDRACHT_DOCKEDSTATE_H
#define EINDOPDRACHT_DOCKEDSTATE_H

#include "BaseState.h"

class DockedState : public BaseState {
public:
    DockedState() = default;
    void Init() override;
    void Update() override;
    void Pause() override;
    void Resume() override;
    void Cleanup() override;
    StateEnum GetName() override {
        return Docked;
    };
private:

};

#endif //EINDOPDRACHT_DOCKEDSTATE_H
