//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUINPUTHANDLER_H
#define AP_PACMAN_MENUINPUTHANDLER_H

#include "../../core/IInputHandler.h"
#include "states/IStateInputHandler.h"

namespace renderer {

    class MenuInputHandler : public IStateInputHandler {
    public:
        void processInput(sf::Event &event, StateManager& stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_MENUINPUTHANDLER_H
