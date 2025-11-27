//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_MENUSTATE_H
#define AP_PACMAN_MENUSTATE_H

#include "core/states/DelegatingState.h"
#include <memory>

namespace renderer {

    /**
     * State representing the main menu of the game.
     * Handles menu navigation and selections.
     *
     * Displays title and press key to go to level state.
     */
    class MenuState : public DelegatingState<MenuState> {
    public:
        MenuState(std::unique_ptr<IStateUpdateHandler<MenuState>>&& updateHandler,
                  std::unique_ptr<IStateInputHandler<MenuState>>&& inputHandler,
                  std::unique_ptr<IStateDrawHandler<MenuState>>&& drawHandler);

        friend class MenuInputHandler;
    };

} // renderer

#endif //AP_PACMAN_MENUSTATE_H
