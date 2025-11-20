//
// Created by rune-suy on 11/5/25.
//

#include "core/world/objects/WorldObject.h"

namespace logic {
    const Position &WorldObject::getPosition() const {
        return position;
    }

    void WorldObject::setPosition(const Position &position) {
        this->position = position;
    }

    void WorldObject::markForRemoval() {
        markedForRemoval = true;
    }

    bool WorldObject::isMarkedForRemoval() const {
        return markedForRemoval;
    }
} // logic