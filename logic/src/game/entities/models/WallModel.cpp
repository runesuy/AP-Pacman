//
// Created by rune-suy on 11/5/25.
//

#include "game/entities/models/WallModel.h"

namespace logic
{
    void WallModel::setSize(const Size& size)
    {
        EntityModel::setSize(size);
        updateObservers();
    }

    void WallModel::setPosition(const Position& position)
    {
        WorldObject::setPosition(position);
        updateObservers();
    }
} // logic
