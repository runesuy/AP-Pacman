//
// Created by runes on 21/11/2025.
//

#include "core/world/LifeCounter.h"
#include <algorithm>

namespace logic {
    const unsigned int LifeCounter::getLifeStart() {
        return lifeStart;
    }

    unsigned int LifeCounter::getLivesLeft() const {
        return livesLeft;
    }

    void LifeCounter::addLives(unsigned int amount) {
        if (amount + livesLeft > lifeStart) livesLeft = lifeStart;
        else livesLeft += amount;
    }

    void LifeCounter::removeLives(unsigned int amount) {
        if (livesLeft < amount) livesLeft = 0;
        else livesLeft -= amount;
    }
} // logic