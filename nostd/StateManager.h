#ifndef EINDOPDRACHT_STATEMANAGER_H
#define EINDOPDRACHT_STATEMANAGER_H

#include "BaseState.h"
#include "Stack.h"

namespace nostd {
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
        Stack<BaseState*> _stateStack;
    };
} //nostd
#endif //EINDOPDRACHT_STATEMANAGER_H
