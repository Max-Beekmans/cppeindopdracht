#ifndef EINDOPDRACHT_RANGE_H
#define EINDOPDRACHT_RANGE_H
#include "Random.h"

namespace nostd {
    class Range {
    public:
        Range(const int minValue, const int maxValue) : _minValue(minValue), _maxValue(maxValue) {}

        ~Range() = default;

        const int GetRandom() {
            return _r.getRand(_minValue, _maxValue);
        }

    private:
        const int _minValue;
        const int _maxValue;
        nostd::Random _r;
    };
} //nostd
#endif //EINDOPDRACHT_RANGE_H
