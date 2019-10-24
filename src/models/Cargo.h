#ifndef EINDOPDRACHT_CARGO_H
#define EINDOPDRACHT_CARGO_H

#include <ostream>
#include "nostd/String.h"
namespace models {
    class Cargo {
    public:
        Cargo() noexcept : _cargo_name{""}, _cost(0), _amount(0) {};

        ~Cargo() = default;

        Cargo(const nostd::String _cargo_name, const int cost, const int amount) : _cargo_name{_cargo_name},
                                                                                   _cost{cost}, _amount{amount} {};

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

        bool operator==(const Cargo &a) {
            return (a._cargo_name == this->_cargo_name);
        }

        const nostd::String GetCargoName() const {
            return _cargo_name;
        }

        const int GetCost() const {
            return _cost;
        }

        const int GetAmount() const {
            return _amount;
        }

        int DeductAmount(const int amount) {
            if (amount > _amount || amount < 0) {
                return -1;
            }
            _amount -= amount;
            return _amount;
        }

        void IncreaseAmount(const int amount) {
            _amount += amount;
        }

    private:
        nostd::String _cargo_name;
        int _cost;
        int _amount;
    };
}
#endif //EINDOPDRACHT_CARGO_H
