//
// Created by runes on 3/11/2025.
//

#include "core/utils/Random.h"

namespace logic {
    std::shared_ptr<Random> Random::getInstance() {
        if (!_instance) {
            _instance = std::shared_ptr<Random>(new Random());
        }
        return _instance;
    }

    int Random::getIntInRange(int min, int max) {
        std::uniform_int_distribution distribution(min, max);
        return distribution(generator);
    }

    Random::Random() {
        std::random_device rd;
        std::seed_seq seed {rd(), rd(), rd(), rd(), rd(), rd()};
        generator.seed(seed);
    }
}