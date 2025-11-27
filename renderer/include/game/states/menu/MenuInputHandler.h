//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUINPUTHANDLER_H
#define AP_PACMAN_MENUINPUTHANDLER_H

#include "core/states/IStateInputHandler.h"
#include "MenuState.h"

namespace renderer {
    class IState;

    /**
     * Input handler for the MenuState, processing user inputs in the main menu.
     * Listens for key presses to transition to the level state.
     */
    class MenuInputHandler : public IStateInputHandler<MenuState> {
    public:
        void processInput(sf::Event &event, StateManager& stateManager, MenuState& state) override;
    };

} // renderer

#endif //AP_PACMAN_MENUINPUTHANDLER_H
