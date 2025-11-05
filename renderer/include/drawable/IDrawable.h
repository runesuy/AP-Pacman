//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IDRAWABLE_H
#define AP_PACMAN_IDRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace renderer {
    class IDrawable {
    public:
        virtual void draw(sf::RenderWindow& window)=0;
    };
}


#endif //AP_PACMAN_IDRAWABLE_H
