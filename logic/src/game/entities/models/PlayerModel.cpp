//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/models/PlayerModel.h"
#include "game/entities/controllers/PlayerController.h"

namespace logic {
    void PlayerModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void PlayerModel::setSize(const Size &size) {
        EntityModel::setSize(size);
        updateObservers();
    }

    PlayerModel::PlayerModel() {
        setController(std::make_shared<PlayerController>());
    }

    float PlayerModel::getSpeed() const {
        return SPEED;
    }

    void PlayerModel::setDirection(Direction direction) {
        MovingEntityModel::setDirection(direction);
        updateObservers();
    }

    SizedWorldObject::CollisionTypeT PlayerModel::getCollisionType() const {
        return collisionType;
    }
} // logic