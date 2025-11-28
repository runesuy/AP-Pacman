//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATE_H
#define AP_PACMAN_PAUSEDSTATE_H
#include "core/states/DelegatingState.h"
#include "core/drawable/ui/Label.h"
#include "core/drawable/ui/Button.h"

namespace renderer {

    class PausedState  : public IState {
        Label pausedLabel;
        inline static const std::string pausedLabelText = "PAUSED";
        inline static const float pausedLabelCharSize = 0.1;

        Button continueButton;
        inline static const std::string continueButtonText = "CONTINUE";
        Button menuButton;
        inline static const std::string menuButtonText = "MENU";
    public:
        PausedState();

        void update() override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATE_H
