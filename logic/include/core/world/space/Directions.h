//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_DIRECTIONS_H
#define AP_PACMAN_DIRECTIONS_H
#include <vector>

#include "Position.h"

namespace logic {
    /**
     * Possible direction a entity can face.
     */
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    /**
     * Returns the opposite of direction.
     * Opposite of NONE is NONE
     * @param direction
     * @return The opposite direction of direction
     */
    Direction getOppositeDirection(Direction direction);

    /**
     * Returns the direction from positionFrom to positionTo.
     * Returns NONE if positions are equal or not aligned.
     * @param positionFrom
     * @param positionTo
     * @return
     */
    Direction getDirectionTo(Position positionFrom , Position positionTo);
}
#endif //AP_PACMAN_DIRECTIONS_H