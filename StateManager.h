#ifndef EINDOPDRACHT_STATEMANAGER_H
#define EINDOPDRACHT_STATEMANAGER_H

#include "BaseState.h"
#include "nostd/Stack.h"

class StateManager {
public:
    StateManager();

    ~StateManager();

    void PopAll();

    void PushState(BaseState* state);

    void PopState();

    bool IsEmpty() const;

    BaseState* CurrentState() {
        return _stateStack.Top();
    }

private:
    nostd::Stack<BaseState*> _stateStack;
};

#endif //EINDOPDRACHT_STATEMANAGER_H
