#ifndef EINDOPDRACHT_CARGO_H
#define EINDOPDRACHT_CARGO_H

#include "nostd/Range.h"

class Cargo {
public:
    Cargo(const int minCost, const int maxCost, const int minAmount, const int maxAmount) : _cost{minCost, maxCost}, _amount{minAmount, maxAmount} {};
    ~Cargo() = default;
    const int GetCost() {
        return _cost.GetRandom();
    }
    const int GetAmount() {
        return _amount.GetRandom();
    }
private:
    nostd::Range _cost;
    nostd::Range _amount;
};

#endif //EINDOPDRACHT_CARGO_H
