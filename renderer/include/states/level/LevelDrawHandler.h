//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELDRAWHANDLER_H
#define AP_PACMAN_LEVELDRAWHANDLER_H

#include "core/IDrawHandler.h"

namespace renderer {

    /**
     * Draw handler for the LevelState, responsible for rendering the game level and its entities.
     */
class LevelDrawHandler : public IDrawHandler {
    public:
        void draw(sf::RenderWindow &window) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELDRAWHANDLER_H
