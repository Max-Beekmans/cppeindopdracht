#ifndef EINDOPDRACHT_SHIP_H
#define EINDOPDRACHT_SHIP_H

#include <ostream>
#include "nostd/String.h"
#include "nostd/Array.h"
#include "Cannon.h"

//TODO: move FleeLookupTable to more logical class

class Ship {
public:
    Ship() noexcept : _type{}, _cost(0), _space(0), _maxCannons(0), _maxHp(0), _weight(0), _isSmall(false), _currentHp(0) {};
    ~Ship() = default;

    Ship(const nostd::String type, const int cost, const int space, const int maxCannons, const int maxHp, const int weight, const bool isSmall)
        : _type(type), _cost(cost), _space(space), _maxCannons(maxCannons), _maxHp(maxHp), _currentHp(maxHp), _weight(weight), _isSmall(isSmall) {}

    nostd::String GetType() {
        return _type;
    }

    friend std::ostream &operator<<(std::ostream &os, Ship &ship) {
        return os << ship._cost << ", " << ship._space << ", " << ship._maxCannons << ", " << ship._maxHp << ", " << ship._weight << ", " << ship._isSmall << ", " << ship._type;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship) {
        return os << ship._cost << ", " << ship._space << ", " << ship._maxCannons << ", " << ship._maxHp << ", " << ship._weight << ", " << ship._isSmall << ", " << ship._type;
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
    void ReceiveDamage(int damage) {
        _currentHp -= damage;
    }
    void RestoreHp(int hp) {
        _currentHp += hp;
    }
    void AddCannon(Cannon cannon) {
        if (_cannons.size() < _maxCannons) {
            _cannons.addBack(cannon);
        }
    }

private:
    nostd::Array<Cannon> _cannons;
    nostd::String _type;
    int _maxHp;
    int _currentHp;
    int _cost;
    int _space;
    int _maxCannons;
    int _weight;
    bool _isSmall;
};

#endif //EINDOPDRACHT_SHIP_H
