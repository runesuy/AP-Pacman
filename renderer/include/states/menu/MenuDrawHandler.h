//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUDRAWHANDLER_H
#define AP_PACMAN_MENUDRAWHANDLER_H

#include "../../core/IDrawHandler.h"

namespace renderer {
    class MenuDrawHandler : public IDrawHandler {
    public:
        void draw(sf::RenderWindow &window) override;
    };
}
#endif //AP_PACMAN_MENUDRAWHANDLER_H
