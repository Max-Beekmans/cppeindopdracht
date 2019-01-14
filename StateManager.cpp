#include "StateManager.h"

StateManager::StateManager() { this->_stateStack = {}; }

/*clears all states of game*/
void StateManager::PopAll() {
    while (!IsEmpty())
    {
        BaseState* poppedState = this->_stateStack.Pop();
        delete poppedState;
    }
}

/* Leave current state and go to previous state*/
void StateManager::PopState() {
    if (!IsEmpty()) {
        BaseState* poppedState = this->_stateStack.Pop();
        delete poppedState;
    }
}

/*Pause the current state and go to a new state which is added at the end of the stack*/
void StateManager::PushState(BaseState *state) {
    this->_stateStack.Push(state);
}

void StateManager::PushAndReplace(BaseState *state) {
    /*Cleanup the current state*/
    if (!IsEmpty()) {
        BaseState* poppedState = this->_stateStack.Pop();
        delete poppedState;
    }
    /*add and initialize the new state*/
    this->_stateStack.Push(state);
}

bool StateManager::IsEmpty() const {
    return this->_stateStack.IsEmpty();
}

StateManager::~StateManager(){
    PopAll();
}