//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_HALL_H
#define EINDOPDRACHT_HALL_H

#include "Coordinate.h"

class Hall {
public:
    Hall() : enda(nullptr), endb(nullptr) {}
    Hall(const Coordinate& enda, const Coordinate& endb) : enda(&enda), endb(&endb) {}
//    Hall(const int x1, const int y1, const int x2, const int y2) {
//        enda = new Coordinate(x1, y1);
//        endb = new Coordinate(x2, y2);
//    }
    ~Hall() {
//        delete enda;
//        delete endb;
    }

    //We save the coordinates of the adjacent rooms const
    const Coordinate* enda;
    const Coordinate* endb;
private:
    bool _visible = false;
};


#endif //EINDOPDRACHT_HALL_H
