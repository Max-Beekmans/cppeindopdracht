//
// Created by MaxBe on 10/22/2018.
//

#ifndef EINDOPDRACHT_HALL_H
#define EINDOPDRACHT_HALL_H

#include "Coordinate.h"

class Hall {
public:
    Hall() : enda(nullptr), endb(nullptr), _visible(false), _orientation(-1) {}
    Hall(const Coordinate& enda, const Coordinate& endb, int orientation) : enda(&enda), endb(&endb), _orientation(orientation), _visible(true) {}
    Hall(const Hall& copy) { copy_from(copy); }
    Hall(Hall&& move) noexcept { move_from(move); }
    ~Hall() {
//        delete enda;
//        delete endb;
    }

    Hall& operator=(const Hall& copy) {
        if (this == &copy) return *this;
        this->copy_from(copy);
        return *this;
    }

    Hall& operator=(Hall&& move) noexcept {
        if (this == &move) return *this;
        this->move_from(move);
        return *this;
    }

    const char GetChar() {
        if (_visible || _orientation > -1) {
            //horizontal
            if (_orientation == 0) {
                return '-';
            } else if (_orientation == 1) {
                return '|';
            }
        }
        return ' ';
    }

    //We save the coordinates of the adjacent rooms const
    const Coordinate* enda;
    const Coordinate* endb;
private:
    void copy_from(const Hall& copy) {
        this->enda = copy.enda;
        this->endb = copy.endb;
        this->_orientation = copy._orientation;
        this->_visible = copy._visible;
    }

    void move_from(Hall& move) {
        this->enda = move.enda;
        this->endb = move.endb;
        this->_orientation = move._orientation;
        this->_visible = move._visible;
    }

    bool _visible = true;
    int _orientation = -1;
};


#endif //EINDOPDRACHT_HALL_H
