#ifndef EINDOPDRACHT_BASESTATE_H
#define EINDOPDRACHT_BASESTATE_H

#include "nostd/StateEnum.h"
#include "nostd/IOHandler.h"

class BaseState {
public:
    virtual void Init()=0;
    virtual void Update()=0;
    virtual void Pause()=0;
    virtual void Resume()=0;
    virtual void Cleanup()=0;
    virtual StateEnum GetName() { return Base; };
private:
    nostd::IOHandler io;
};

#endif //EINDOPDRACHT_BASESTATE_H
