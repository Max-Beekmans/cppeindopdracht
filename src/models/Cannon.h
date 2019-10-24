#ifndef EINDOPDRACHT_CANNON_H
#define EINDOPDRACHT_CANNON_H

#include <ostream>
#include "../nostd/Range.h"
#include "../nostd/String.h"

namespace models {
    class Cannon {
    public:
        explicit Cannon(const int weight, const int cost, const int amount) : _weight(weight), _cost(cost),
                                                                              _amount(amount) {}

        Cannon() : _weight(0), _cost(0), _amount(0) {};

        ~Cannon() = default;

        friend std::ostream &operator<<(std::ostream &os, Cannon &cannon) {
            switch (cannon._weight) {
                case 0:
                    os << "Light cannons: ";
                    break;
                case 1:
                    os << "Medium cannons: ";
                    break;
                case 2:
                    os << "Heavy cannons: ";
                default:
                    os << " ";
            }
            if (cannon._amount < 1) {
                os << "UNAVAILABLE";
            } else {
                os << cannon._amount << " available";
            }
            os << cannon._cost << " g" << std::endl;
            return os;
        }

        friend std::ostream &operator<<(std::ostream &os, const Cannon &cannon) {
            return os << cannon._weight << ", " << cannon._cost;
        }

        bool operator==(const Cannon &a) {
            return (a._weight == this->_weight);
        }

        const int GetDamage() {
            int maxRange = 0;
            switch (_weight) {
                case 0:
                    maxRange = 2;
                    break;
                case 1:
                    maxRange = 4;
                    break;
                case 2:
                    maxRange = 6;
                    break;
                default:
                    maxRange = 0;
                    break;
            }
            nostd::Range range{0, maxRange};
            return range.GetRandom();
        }

        const int GetWeight() const {
            return _weight;
        }

        const int GetCost() const {
            return _cost;
        }

        const int GetAmount() const {
            return _amount;
        }

        const nostd::string GetStringWeight() const {
            switch (_weight) {
                case 0:
                    return std::string{"Light cannon"};
                case 1:
                    return nostd::String{"Medium cannon"};
                case 2:
                    return nostd::String{"Heavy cannon"};
                default:
                    return nostd::String{"Invalid cannon"};
            }
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
        int _weight;
        int _cost;
        int _amount;
    };
}
#endif //EINDOPDRACHT_CANNON_H
