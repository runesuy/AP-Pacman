//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/controllers/PowerupController.h"

namespace logic {
    void PowerupController::update(World &world, FruitModel &entity) {

    }

    void PowerupController::processCommand(EntityCommand command, FruitModel &entity) {

    }

    void PowerupController::onCollision(FruitModel &entity, const SizedWorldObject &other, World& world) {
        CollectableController<logic::FruitModel>::onCollision(entity, other, world);
        entity.updateObservers();
    }
} // logic