//
// Created by rune-suy on 11/9/25.
//

#include "game/entities/models/PowerupModel.h"
#include "game/entities/models/PlayerModel.h"
#include "game/entities/controllers/PowerupController.h"

namespace logic {
    void PowerupModel::setSize(const Size &size) {
        SizedWorldObject::setSize(size);
        updateObservers();
    }

    void PowerupModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void PowerupModel::markForRemoval() {
        WorldObject::markForRemoval();
        updateObservers();
    }

    PowerupModel::PowerupModel() {
        controller = std::make_shared<PowerupController>();
    }
} // logic