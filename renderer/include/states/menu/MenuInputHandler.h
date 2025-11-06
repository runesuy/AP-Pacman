//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUINPUTHANDLER_H
#define AP_PACMAN_MENUINPUTHANDLER_H

#include "states/IStateInputHandler.h"

namespace renderer {
    class IState;

    class MenuInputHandler : public IStateInputHandler {
    public:
        void processInput(sf::Event &event, StateManager& stateManager, IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_MENUINPUTHANDLER_H
