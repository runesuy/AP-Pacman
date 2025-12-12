//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_MENUSTATE_H
#define AP_PACMAN_MENUSTATE_H

#include "core/states/IState.h"
#include "core/drawable/ui/Button.h"
#include <memory>
#include "core/parsers/TXTHighScoreParser.h"

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

        Label highScoreLabel;
        std::unique_ptr<logic::IHighScoreParser> highScoreParser = std::make_unique<logic::TXTHighScoreParser>();

        void onPlayButtonClick(StateManager &stateManager) const;

    public:
        MenuState();

        friend class MenuInputHandler;
        friend class MenuDrawHandler;

        void update(StateManager &stateManager) override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;

        void onManagerReActive() override;
    };
} // renderer

#endif //AP_PACMAN_MENUSTATE_H
