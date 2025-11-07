//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/models/PlayerModel.h"

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
} // logic