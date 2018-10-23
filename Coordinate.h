//
// Created by Max on 10/23/2018.
//

#ifndef EINDOPDRACHT_COORDINATE_H
#define EINDOPDRACHT_COORDINATE_H

class Coordinate {
public:
    Coordinate(): x(-1), y(-1) {}
    Coordinate(const int x, const int y) : x(x), y(y) {}
    Coordinate(const Coordinate& other) : x{other.x}, y{other.y} {}

//    Coordinate& operator=(const Coordinate& other) {
//        if (this == &other) return *this;
//    }
    const int x = 0;
    const int y = 0;
};

#endif //EINDOPDRACHT_COORDINATE_H
