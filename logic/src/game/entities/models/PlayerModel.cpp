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

    PlayerModel::Direction PlayerModel::getDirection() const {
        return direction;
    }

    void PlayerModel::setDirection(PlayerModel::Direction direction) {
        PlayerModel::direction = direction;
    }

    PlayerModel::PlayerModel() {
        setController(std::make_shared<PlayerController>());
    }

    float PlayerModel::getSpeed() const {
        return SPEED;
    }

    PlayerModel::Direction PlayerModel::getRequestedDirection() const {
        return requestedDirection;
    }

    void PlayerModel::setRequestedDirection(PlayerModel::Direction requestedDirection) {
        PlayerModel::requestedDirection = requestedDirection;
    }
} // logic