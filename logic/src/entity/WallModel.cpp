//
// Created by rune-suy on 11/5/25.
//

#include "entity/WallModel.h"

namespace logic {
    void WallModel::update() {}

    void WallModel::setSize(const Size &size) {
        EntityModel::setSize(size);
        updateObservers();
    }

    void WallModel::setPosition(const Position &position) {
        WorldObject::setPosition(position);
        updateObservers();
    }
} // logic