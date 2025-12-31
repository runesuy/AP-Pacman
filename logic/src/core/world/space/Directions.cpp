//
// Created by runes on 20/11/2025.
//
#include "core/world/space/Directions.h"
#include <vector>
#include <algorithm>

namespace logic
{
    Direction getOppositeDirection(Direction direction)
    {
        switch (direction)
        {
        case NONE: return NONE;
        case RIGHT: return LEFT;
        case LEFT: return RIGHT;
        case UP: return DOWN;
        case DOWN: return UP;
        }
        return NONE;
    }

    Direction getDirectionTo(Position positionFrom, Position positionTo)
    {
        const double eps = 0.001;
        // scale positions so vecTo cant be outsider Position scope
        // does not affect the direction and so the result
        auto posFromN = positionFrom * 0.5;
        auto posToN = positionTo * 0.5;
        auto vecTo = posToN + (posFromN * -1);

        // UP OR DOWN
        if (std::abs(vecTo.getX()) < eps)
        {
            if (vecTo.getY() > 0)
            {
                return UP;
            }
            if (vecTo.getY() < 0)
            {
                return DOWN;
            }
            return NONE;
        }
        // LEFT OR RIGHT
        if (std::abs(vecTo.getY()) < eps)
        {
            if (vecTo.getX() > 0)
            {
                return RIGHT;
            }
            if (vecTo.getX() < 0)
            {
                return LEFT;
            }
            return NONE;
        }
        return NONE;
    }
}
