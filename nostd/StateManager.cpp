#include "StateManager.h"

namespace nostd {

StateManager::StateManager() { this->_stateStack = {}; }

/*clears all states of game*/
void StateManager::PopAll() {
    while (!IsEmpty())
    {
        BaseState *poppedState = this->_stateStack.Pop();
        poppedState->Cleanup();
        delete poppedState;
    }
}

/* Leave current state and go to previous state*/
void StateManager::PopState() {
    if (!IsEmpty()) {
        BaseState *poppedState = this->_stateStack.Pop();
        poppedState->Cleanup();
        delete poppedState;

    }
    if (!IsEmpty()) this->_stateStack.Top()->Resume();
}

/*Pause the current state and go to a new state which is added at the end of the stack*/
void StateManager::PushState(BaseState *state) {
    if (!IsEmpty()) this->_stateStack.Top()->Pause();
    this->_stateStack.Push(state);
    this->_stateStack.Top()->Init();
}

bool StateManager::IsEmpty() const {
    return this->_stateStack.IsEmpty() == 0;
}

StateManager::~StateManager(){
    PopAll();
}
} //nostd