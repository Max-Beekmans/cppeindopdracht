#ifndef EINDOPDRACHT_SHIP_H
#define EINDOPDRACHT_SHIP_H

#include <ostream>
#include "nostd/String.h"
#include "nostd/Array.h"
#include "Cannon.h"
#include "Cargo.h"

//TODO: move FleeLookupTable to more logical class

class Ship {
public:
    Ship() noexcept : _type{}, _cost(0), _space(0), _maxCannons(0), _maxHp(0), _weight(1), _isSmall(false), _currentHp(0) {};
    ~Ship() = default;

    Ship(const nostd::String type, const int cost, const int space, const int maxCannons, const int maxHp, const int weight, const bool isSmall)
        : _type(type), _cost(cost), _space(space), _maxCannons(maxCannons), _maxHp(maxHp), _currentHp(maxHp), _weight(weight), _isSmall(isSmall) {}

    nostd::String GetType() const {
        return _type;
    }

    friend std::ostream &operator<<(std::ostream &os, Ship &ship) {
        os << "type:        " << ship._type << std::endl;
        os << "cost:        " << ship._cost << std::endl;
        os << "space:       " << ship._space << std::endl;
        os << "max cannons: " << ship._maxCannons << std::endl;
        os << "max hp:      " << ship._maxHp << std::endl;
        os << "weight:      ";
        switch(ship._weight) {
            case 0:
                os << "light";
                break;
            case 1:
                os << "normal";
                break;
            case 2:
                os << "heavy";
                break;
            default:
                os << " ";
        }
        os << std::endl;
        os << "size:        ";
        if(ship._isSmall) {
            os << "small" << std::endl;
        } else {
            os << "large" << std::endl;
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship) {
        os << "type:        " << ship._type << std::endl;
        os << "cost:        " << ship._cost << std::endl;
        os << "space:       " << ship._space << std::endl;
        os << "max cannons: " << ship._maxCannons << std::endl;
        os << "max hp:      " << ship._maxHp << std::endl;
        os << "weight:      ";
        switch(ship._weight) {
            case 0:
                os << "light";
                break;
            case 1:
                os << "normal";
                break;
            case 2:
                os << "heavy";
                break;
            default:
                os << " ";
        }
        os << std::endl;
        os << "size:        ";
        if(ship._isSmall) {
            os << "small" << std::endl;
        } else {
            os << "large" << std::endl;
        }
        return os;
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
    nostd::Array<Cannon> GetCannons() {
        return _cannons;
    }
    void AddCargo(Cargo cargo) {
        //check on if there is space or will we be doing this check in the shop?
        _cargo.addBack(cargo);
    }
    //Remove cargo when amount < 1
    void RemoveCargo(size_t n) {
        _cargo.removeN(n);
    }
    nostd::Array<Cargo> GetCargo() {
        return _cargo;
    }
    void LoseAllCargo() {
        //this is the correct way to empty an array right?
        _cargo = {};
    }
private:
    nostd::Array<Cannon> _cannons;
    nostd::Array<Cargo> _cargo;
    nostd::String _type;
    int _maxHp;
    int _currentHp;
    int _cost;
    int _space;
    int _maxSpace;
    int _cannon_amount;
    int _maxCannons;
    //0 == light, 1 == normal, 2 == heavy
    int _weight;
    bool _isSmall;
};

#endif //EINDOPDRACHT_SHIP_H
