//
// Created by rune-suy on 11/5/25.
//

#include "world/WorldObject.h"

namespace logic {
    const Position &WorldObject::getPosition() const {
        return position;
    }

    void WorldObject::setPosition(const Position &position) {
        this->position = position;
    }
} // logic