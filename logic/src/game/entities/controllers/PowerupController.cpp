//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/controllers/PowerupController.h"

namespace logic {
    void PowerupController::update(World &world, PowerupModel &entity) {

    }

    void PowerupController::processCommand(EntityCommand command, PowerupModel &entity) {

    }

    void PowerupController::onCollision(PowerupModel &entity, WorldObject &other) {
        CollectableController<logic::PowerupModel>::onCollision(entity, other);
        entity.updateObservers();
    }
} // logic