//
// Created by rune-suy on 11/8/25.
//

#include "game/entities/models/CoinModel.h"
#include "game/entities/models/PlayerModel.h"

namespace logic {
    void CoinModel::setSize(const Size &size) {
        EntityModel::setSize(size);
        updateObservers();
    }

    void CoinModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void CoinModel::onCollision(WorldObject &other) {
        // if collision with player
        if (dynamic_cast<EntityModel<PlayerModel>*>(&other)) {
            markForRemoval();
            updateObservers();
        }
    }

    void CoinModel::markForRemoval() {
        WorldObject::markForRemoval();
        updateObservers();
    }
} // logic