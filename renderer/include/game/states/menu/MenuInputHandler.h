//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUINPUTHANDLER_H
#define AP_PACMAN_MENUINPUTHANDLER_H

#include "core/states/IStateInputHandler.h"

namespace renderer {
    class IState;

    /**
     * Input handler for the MenuState, processing user inputs in the main menu.
     * Listens for key presses to transition to the level state.
     */
    class MenuInputHandler : public IStateInputHandler {
    public:
        void processInput(sf::Event &event, StateManager& stateManager, IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_MENUINPUTHANDLER_H
