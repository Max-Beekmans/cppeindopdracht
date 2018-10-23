//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_HALL_H
#define EINDOPDRACHT_HALL_H

#include "Room.h"

class Hall {
public:
    Hall();
    Hall(const Room* enda, const Room* endb);

    //I guess we just hold the pointers and promise to not alter the rooms.
    //I just wanna look at them right?
    const Room* enda;
    const Room* endb;
private:
    bool _visible = false;
};


#endif //EINDOPDRACHT_HALL_H
