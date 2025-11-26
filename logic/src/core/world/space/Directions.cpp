//
// Created by runes on 20/11/2025.
//
#include "core/world/space/Directions.h"
#include <vector>
#include <algorithm>

namespace logic {

    Direction getOppositeDirection(Direction direction) {
        switch (direction) {
            case NONE: return NONE;
            case RIGHT: return LEFT;
            case LEFT: return RIGHT;
            case UP: return DOWN;
            case DOWN: return UP;
        }
        return NONE;
    }
}