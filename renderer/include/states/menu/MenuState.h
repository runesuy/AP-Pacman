//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_MENUSTATE_H
#define AP_PACMAN_MENUSTATE_H

#include "../DelegatingState.h"
#include <memory>

namespace renderer {

    /**
     * State representing the main menu of the game.
     * Handles menu navigation and selections.
     *
     * Displays title and press key to go to level state.
     */
    class MenuState : public DelegatingState {
    public:
        MenuState(std::unique_ptr<IStateUpdateHandler>&& updateHandler,
                  std::unique_ptr<IStateInputHandler>&& inputHandler,
                  std::unique_ptr<IDrawHandler>&& drawHandler);
    };

} // renderer

#endif //AP_PACMAN_MENUSTATE_H
