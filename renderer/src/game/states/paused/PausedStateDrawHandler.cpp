//
// Created by runes on 27/11/2025.
//

#include "game/states/paused/PausedStateDrawHandler.h"
#include "core/utils/Camera.h"

namespace renderer {
    void PausedStateDrawHandler::draw(sf::RenderWindow &window, IState &state) {
        pausedLabel.draw(window);
        descrLabel.draw(window);
    }

    PausedStateDrawHandler::PausedStateDrawHandler() {
        pausedLabel.setString(pausedLabelText);
        descrLabel.setString(descrLabelText);
        pausedLabel.setHorizontalOrigin(Label::MIDDLE);
        descrLabel.setHorizontalOrigin(Label::MIDDLE);
        pausedLabel.setCharacterSize(pausedLabelCharSize);
        descrLabel.setCharacterSize(descrLabelCharSize);
        pausedLabel.setPosition({0,0.3});
        descrLabel.setPosition({0,0});
    }
} // renderer