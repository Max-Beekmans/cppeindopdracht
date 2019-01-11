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
        return os << cargo._cargo_name << ", " << cargo._amount << ", " << cargo._cost;
    }

    friend std::ostream &operator<<(std::ostream &os, const Cargo &cargo) {
        return os << cargo._cargo_name << ", " << cargo._amount << ", " << cargo._cost;
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
