//
// Created by runes on 27/11/2025.
//

#include "game/states/paused/PausedStateDrawHandler.h"
#include "core/utils/Camera.h"

namespace renderer {
    void PausedStateDrawHandler::draw(sf::RenderWindow &window, PausedState &state, StateManager& stateManager) {
        pausedLabel.draw(window);
        menuButton.draw(window);
        continueButton.draw(window);
    }

    PausedStateDrawHandler::PausedStateDrawHandler() {
        pausedLabel.setString(pausedLabelText);
        pausedLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        pausedLabel.setCharacterSize(pausedLabelCharSize);
        pausedLabel.setPosition({0,0.3});
        menuButton.setString(menuButtonText);
        menuButton.setCharacterSize(0.05);
        menuButton.setPosition({-0.3,0});
        continueButton.setString(continueButtonText);
        continueButton.setCharacterSize(0.05);
        continueButton.setPosition({0.3, 0});
    }
} // renderer