#ifndef EINDOPDRACHT_CANNON_H
#define EINDOPDRACHT_CANNON_H

#include "nostd/Range.h"

class Cannon {
public:
    ~Cannon() = default;
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
