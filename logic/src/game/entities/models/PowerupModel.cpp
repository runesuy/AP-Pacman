//
// Created by rune-suy on 11/9/25.
//

#include "game/entities/models/FruitModel.h"
#include "game/entities/models/PlayerModel.h"
#include "game/entities/controllers/PowerupController.h"

namespace logic {
    void FruitModel::setSize(const Size &size) {
        SizedWorldObject::setSize(size);
        updateObservers();
    }

    void FruitModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void FruitModel::markForRemoval() {
        WorldObject::markForRemoval();
        updateObservers();
    }

    FruitModel::FruitModel() {
        controller = std::make_shared<PowerupController>();
    }

    SizedWorldObject::CollisionTypeT FruitModel::getCollisionType() const {
        return FRUIT;
    }
} // logic