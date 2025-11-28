//
// Created by runes on 28/11/2025.
//

#ifndef AP_PACMAN_GAMEOVERSTATE_H
#define AP_PACMAN_GAMEOVERSTATE_H

#include "core/states/IState.h"
#include "core/drawable/ui/Label.h"

namespace renderer {

    class GameOverState : public IState{
        Label gameOverLabel{"GAME OVER"};
        Label descrLabel{"PRESS ANY KEY TO CONTINUE"};
    public:
        GameOverState();
        void update(StateManager &stateManager) override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_GAMEOVERSTATE_H
