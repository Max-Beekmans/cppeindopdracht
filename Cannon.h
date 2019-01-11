#ifndef EINDOPDRACHT_CANNON_H
#define EINDOPDRACHT_CANNON_H

#include <ostream>
#include "nostd/Range.h"

class Cannon {
public:
    explicit Cannon(const int weight, const int cost) {}
    Cannon() : _weight(0), _cost(0) {};
    ~Cannon() = default;

    friend std::ostream &operator<<(std::ostream &os, Cannon &cannon) {
        return os << cannon._weight << ", " << cannon._cost;
    }
    friend std::ostream &operator<<(std::ostream &os, const Cannon &cannon) {
        return os << cannon._weight << ", " << cannon._cost;
    }

    const int GetDamage() {
        int maxRange = 0;
        switch(_weight) {
            case 0: maxRange = 2;
                break;
            case 1: maxRange = 4;
                break;
            case 2: maxRange = 6;
                break;
            default: maxRange = 0;
                break;
        }
        nostd::Range range{0, maxRange};
        return range.GetRandom();
    }
    const int GetWeight() {
        return _weight;
    }
    const int GetCost() {
        return _cost;
    }
private:
    int _weight;
    int _cost;
};

#endif //EINDOPDRACHT_CANNON_H
