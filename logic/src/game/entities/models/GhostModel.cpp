//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/models/GhostModel.h"
#include "game/entities/controllers/RandomNavGhostController.h"

namespace logic {
    GhostModel::GhostModel() {
        controller = std::make_shared<logic::RandomNavGhostController>();
    }

    void GhostModel::setSize(const Size &size) {
        SizedWorldObject::setSize(size);
        updateObservers();
    }

    void GhostModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void GhostModel::markForRemoval() {
        WorldObject::markForRemoval();
        updateObservers();
    }

    float GhostModel::getSpeed() {
        return SPEED;
    }
} // logic