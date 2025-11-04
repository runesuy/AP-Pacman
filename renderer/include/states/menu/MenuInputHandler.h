//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUINPUTHANDLER_H
#define AP_PACMAN_MENUINPUTHANDLER_H

#include "../../core/IInputHandler.h"

namespace renderer {

    class MenuInputHandler : public IInputHandler {
    public:
        void processInput(sf::Event &event) override;
    };

} // renderer

#endif //AP_PACMAN_MENUINPUTHANDLER_H
