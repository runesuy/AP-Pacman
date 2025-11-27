//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
#define AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
#include "core/states/IStateDrawHandler.h"
#include "core/drawable/ui/Label.h"
#include "core/drawable/ui/Button.h"
#include "PausedState.h"

namespace renderer {

    class PausedStateDrawHandler : public IStateDrawHandler<PausedState>{
        Label pausedLabel;
        inline static const std::string pausedLabelText = "PAUSED";
        inline static const float pausedLabelCharSize = 0.1;

        Button continueButton;
        inline static const std::string continueButtonText = "CONTINUE";
        Button menuButton;
        inline static const std::string menuButtonText = "MENU";

    public:
        PausedStateDrawHandler();
        void draw(sf::RenderWindow &window, PausedState &state, StateManager& stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
