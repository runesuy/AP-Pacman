//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_DIRECTIONS_H
#define AP_PACMAN_DIRECTIONS_H
#include <vector>

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
     * @return
     */
    Direction getOppositeDirection(Direction direction);
}
#endif //AP_PACMAN_DIRECTIONS_H