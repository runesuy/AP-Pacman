//
// Created by rune-suy on 11/8/25.
//

#include "game/entities/models/CoinModel.h"
#include "game/entities/models/PlayerModel.h"
#include "game/entities/controllers/CoinController.h"

namespace logic {
    void CoinModel::setSize(const Size &size) {
        EntityModel::setSize(size);
        updateObservers();
    }

    void CoinModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void CoinModel::markForRemoval() {
        WorldObject::markForRemoval();
        updateObservers();
    }

    CoinModel::CoinModel() {
        controller = std::make_shared<logic::CoinController>();
    }
} // logic