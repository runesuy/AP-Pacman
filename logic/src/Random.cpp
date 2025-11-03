//
// Created by runes on 3/11/2025.
//

#include "Random.h"

namespace logic {
    std::shared_ptr<Random> Random::getInstance() {
        if (!_instance) {
            _instance = std::make_shared<Random>(Random());
        }
        return _instance;
    }
}