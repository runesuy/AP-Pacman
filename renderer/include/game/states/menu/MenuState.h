//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_MENUSTATE_H
#define AP_PACMAN_MENUSTATE_H

#include "core/states/DelegatingState.h"
#include "core/drawable/ui/Button.h"
#include <memory>

namespace renderer {

    /**
     * State representing the main menu of the game.
     * Handles menu navigation and selections.
     *
     * Displays title and press key to go to level state.
     */
    class MenuState : public IState {
        Button playButton;
        bool _fontLoaded = false;
        sf::Font _font;

        void onPlayButtonClick(StateManager& stateManager) const;
    public:
        MenuState();

        friend class MenuInputHandler;
        friend class MenuDrawHandler;

        void update() override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_MENUSTATE_H
