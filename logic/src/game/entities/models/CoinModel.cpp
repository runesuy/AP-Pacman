//
// Created by rune-suy on 11/8/25.
//

#include "game/entities/models/CoinModel.h"

namespace logic {
    void CoinModel::setSize(const Size &size) {
        EntityModel::setSize(size);
        updateObservers();
    }

    void CoinModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }
} // logic