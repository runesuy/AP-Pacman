//
// Created by runes on 28/11/2025.
//

#ifndef AP_PACMAN_GAMEOVERSTATE_H
#define AP_PACMAN_GAMEOVERSTATE_H

#include "core/states/IState.h"
#include "core/drawable/ui/Label.h"
#include "core/world/Score.h"

namespace renderer
{
    /**
     * Displays the game over screen with the final score and waits for user input to continue.
     */
    class GameOverState : public IState
    {
        Label gameOverLabel{"GAME OVER"};
        Label descrLabel{"PRESS ANY KEY TO CONTINUE"};
        Label currentScoreLabel;
        bool keyReleased = false;
        bool firstEvent = true;
    public:
        explicit GameOverState(const std::shared_ptr<logic::Score>& score);

        void update(StateManager& stateManager) override;

        void processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window) override;

        void draw(sf::RenderWindow& window, StateManager& stateManager) override;
    };
} // renderer

#endif //AP_PACMAN_GAMEOVERSTATE_H
