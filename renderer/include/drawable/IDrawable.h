//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IDRAWABLE_H
#define AP_PACMAN_IDRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace renderer {
    /**
     * Interface for drawable objects in the game.
     */
    class IDrawable {
    public:
        /**
         * Draw the object onto the provided render window.
         * @param window
         */
        virtual void draw(sf::RenderWindow& window)=0;
    };
}


#endif //AP_PACMAN_IDRAWABLE_H
