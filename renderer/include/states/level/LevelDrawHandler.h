//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELDRAWHANDLER_H
#define AP_PACMAN_LEVELDRAWHANDLER_H

#include "core/IDrawHandler.h"

namespace renderer {

class LevelDrawHandler : public logic::IDrawHandler {
    public:
        void draw(sf::RenderWindow &window) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELDRAWHANDLER_H
