#ifndef EINDOPDRACHT_BASESTATE_H
#define EINDOPDRACHT_BASESTATE_H

#include "StateEnum.h"
#include "nostd/IOHandler.h"
#include "nostd/Array.h"
#include "nostd/String.h"
#include "Player.h"
#include "StateManager.h"

class BaseState {
public:
    virtual void Update()=0;
    virtual StateEnum GetName() { return Base; };
protected:
    Player* _player;
    StateManager* _stateManager;
    nostd::Array<nostd::String> _options;
    nostd::IOHandler io;
    virtual void print_options()=0;
};

#endif //EINDOPDRACHT_BASESTATE_H
