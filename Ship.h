#ifndef EINDOPDRACHT_SHIP_H
#define EINDOPDRACHT_SHIP_H

#include "nostd/String.h"
#include "nostd/Array.h"

//TODO: move FleeLookupTable to more logical class

class Ship {
public:
    Ship(const nostd::String type, const int cost, const int space, const int maxCannons, const int maxHp, const int weight, const bool isSmall)
        : _type(type), _cost(cost), _space(space), _maxCannons(maxCannons), _maxHp(maxHp), _currentHp(maxHp), _weight(weight), _isSmall(isSmall) {
        initFleeLookupTable();
    }
    ~Ship() = default;
    nostd::String GetType() {
        return _type;
    }
    void initFleeLookupTable() {
        _fleeLookupTable[0][0] = 50;
        _fleeLookupTable[1][0] = 30;
        _fleeLookupTable[2][0] = 5;
        _fleeLookupTable[0][1] = 60;
        _fleeLookupTable[1][1] = 40;
        _fleeLookupTable[2][1] = 15;
        _fleeLookupTable[0][1] = 75;
        _fleeLookupTable[1][1] = 55;
        _fleeLookupTable[2][1] = 30;
    }
    const int GetMaxHp() {
        return _maxHp;
    }
    const int GetCurrentHp() {
        return _currentHp;
    }
    const int GetCost() {
        return _cost;
    }
    const int GetSpace() {
        return _space;
    }
    const int GetMaxCannons() {
        return _maxCannons;
    }
    const int GetWeight() {
        return _weight;
    }
    const bool IsSmall() {
        return _isSmall;
    }
    void receiveDamage(int damage) {
        _currentHp -= damage;
    }
    void restoreHp(int hp) {
        _currentHp += hp;
    }
    int GetFleeChance() {
        return 0;
    }

private:
    const nostd::String _type;
    const int _maxHp;
    int _currentHp;
    const int _cost;
    const int _space;
    const int _maxCannons;
    const int _weight;
    const bool _isSmall;
    int _fleeLookupTable[3][3];
};

#endif //EINDOPDRACHT_SHIP_H
