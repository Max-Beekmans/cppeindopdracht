//
// Created by MaxBe on 10/22/2018.
//

#include "Hall.h"

Hall::Hall() {
    this->enda = nullptr;
    this->endb = nullptr;
}

Hall::Hall(const Room *enda, const Room *endb) {
    this->enda = enda;
    this->endb = endb;
}
