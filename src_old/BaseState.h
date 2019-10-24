#ifndef EINDOPDRACHT_BASESTATE_H
#define EINDOPDRACHT_BASESTATE_H

#include "nostd/IOHandler.h"
#include "nostd/Array.h"
#include "nostd/String.h"
#include "Player.h"

class StateManager;

class BaseState {
public:
    BaseState(Player& player, StateManager& stateManager) : player(player), stateManager(stateManager) {}
    virtual ~BaseState() = default;
    virtual bool Update() = 0;
protected:
    Player& player;
    StateManager& stateManager;
    nostd::Array<nostd::String> options;
    nostd::IOHandler io;
};

#endif //EINDOPDRACHT_BASESTATE_H
