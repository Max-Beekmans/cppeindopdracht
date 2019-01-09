#ifndef EINDOPDRACHT_CARGO_H
#define EINDOPDRACHT_CARGO_H

#include "nostd/String.h"

class Cargo {
public:
    Cargo(const nostd::String _cargo_name, const int cost, const int amount) : _cargo_name{_cargo_name} ,_cost{cost}, _amount{amount} {};
    ~Cargo() = default;
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
    const nostd::String _cargo_name;
    const int _cost;
    const int _amount;
};

#endif //EINDOPDRACHT_CARGO_H
