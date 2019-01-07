//
// Created by MaxBe on 10/15/2018.
//

#ifndef EINDOPDRACHT_RANDOM_H
#define EINDOPDRACHT_RANDOM_H

#include <random>

namespace nostd {
    class Random {
    public:
        const int getRand(const int range_a, const int range_b) {
            std::uniform_int_distribution<int> dist(range_a, range_b);
            getSeed();
            return dist(generator);
        }

    private:
        std::default_random_engine generator;
        std::random_device r;

        void getSeed() {
            generator.seed(r());
        }
    };
}

#endif //EINDOPDRACHT_RANDOM_H
