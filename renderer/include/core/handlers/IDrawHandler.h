//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IDRAWHANDLER_H
#define AP_PACMAN_IDRAWHANDLER_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace renderer {
    /**
     * Interface for handling drawing operations in the game.
     */
    class IDrawHandler {
    public:
        /**
         * Draw the game elements onto the provided render window.
         * @param window
         */
        virtual void draw(sf::RenderWindow &window) = 0;

        virtual ~IDrawHandler() = default;
    };
}


#endif //AP_PACMAN_IDRAWHANDLER_H
