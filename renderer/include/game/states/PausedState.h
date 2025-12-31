//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATE_H
#define AP_PACMAN_PAUSEDSTATE_H
#include "core/states/IState.h"
#include "core/drawable/ui/Label.h"
#include "core/drawable/ui/Button.h"

namespace renderer
{
    /**
     * Displays a paused screen when esc is pressed during gameplay.
     * Gives the option to go to the menu, or continue the game by clicking buttons.
     * Continuing the game can also be done by pressing esc again.
     */
    class PausedState : public IState
    {
        Label pausedLabel;
        inline static const std::string pausedLabelText = "PAUSED";
        static constexpr float pausedLabelCharSize = 0.1;

        Button continueButton;
        inline static const std::string continueButtonText = "CONTINUE";
        Button menuButton;
        inline static const std::string menuButtonText = "MENU";

    public:
        PausedState();

        void update(StateManager& stateManager) override;

        void processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window) override;

        void draw(sf::RenderWindow& window, StateManager& stateManager) override;
    };
} // renderer

#endif //AP_PACMAN_PAUSEDSTATE_H
