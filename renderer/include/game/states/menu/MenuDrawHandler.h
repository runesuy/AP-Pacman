//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUDRAWHANDLER_H
#define AP_PACMAN_MENUDRAWHANDLER_H

#include <SFML/Graphics/Font.hpp>
#include "core/states/IState.h"
#include "core/states/IStateDrawHandler.h"

namespace renderer {
    /**
     * Draw handler for the MenuState, responsible for rendering the main menu.
     */
class MenuDrawHandler : public IStateDrawHandler {
        bool _fontLoaded = false;
        sf::Font _font;
    public:
        void draw(sf::RenderWindow &window, IState& state) override;
    };
}
#endif //AP_PACMAN_MENUDRAWHANDLER_H
