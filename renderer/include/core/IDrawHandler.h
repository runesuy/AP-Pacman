//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IDRAWHANDLER_H
#define AP_PACMAN_IDRAWHANDLER_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace logic {
    class IDrawHandler {
    public:
        virtual void draw(sf::RenderWindow &window) = 0;

        virtual ~IDrawHandler() = default;
    };
}


#endif //AP_PACMAN_IDRAWHANDLER_H
