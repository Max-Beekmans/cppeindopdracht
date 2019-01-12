#ifndef EINDOPDRACHT_CARGO_H
#define EINDOPDRACHT_CARGO_H

#include <ostream>
#include "nostd/String.h"

class Cargo {
public:
    Cargo() noexcept : _cargo_name{""}, _cost(0), _amount(0) {};
    ~Cargo() = default;
    Cargo(const nostd::String _cargo_name, const int cost, const int amount) : _cargo_name{_cargo_name} ,_cost{cost}, _amount{amount} {};

    friend std::ostream &operator<<(std::ostream &os, Cargo &cargo) {
        os << "Name:             " << cargo._cargo_name << std::endl;
        os << "Amount available: " << cargo._amount << std::endl;
        os << "Current price:    " << cargo._cost << std::endl;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const Cargo &cargo) {
        os << "Name:             " << cargo._cargo_name << std::endl;
        os << "Amount available: " << cargo._amount << std::endl;
        os << "Current price:    " << cargo._cost << std::endl;
        return os;
    }

    const nostd::String GetCargoName() {
        return _cargo_name;
    }
    const int GetCost() {
        return _cost;
    }
    const int GetAmount() {
        return _amount;
    }
private:
    nostd::String _cargo_name;
    int _cost;
    int _amount;
};

#endif //EINDOPDRACHT_CARGO_H
