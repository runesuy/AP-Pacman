//
// Created by runes on 28/11/2025.
//

#ifndef AP_PACMAN_VICTORYSTATE_H
#define AP_PACMAN_VICTORYSTATE_H

#include "core/states/IState.h"
#include "core/world/Score.h"
#include "core/drawable/ui/Label.h"

namespace renderer
{
    /**
     * Displays a victory screen when the player completes a level.
     * When a key is pressed, it passes the score to the next level and transitions to the next state.
     */
    class VictoryState : public IState
    {
        std::shared_ptr<logic::Score> passToNextLevel;
        Label victoryLabel{"LEVEL COMPLETE"};
        Label currentScoreLabel;
        const std::string currentScoreLabelPref = "YOUR CURRENT SCORE IS: ";
        Label descrLabel{"PRESS ANY KEY TO CONTINUE"};
        bool keyReleased = false;

    public:
        explicit VictoryState(const std::shared_ptr<logic::Score>& passToNextLevel);

        void update(StateManager& stateManager) override;

        void processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window) override;

        void draw(sf::RenderWindow& window, StateManager& stateManager) override;
    };
} // renderer

#endif //AP_PACMAN_VICTORYSTATE_H
