//
// Created by runes on 27/11/2025.
//

#include "game/states/paused/PausedStateInputHandler.h"
#include "core/states/StateManager.h"

namespace renderer {
    void PausedStateInputHandler::processInput(sf::Event &event, StateManager &stateManager, PausedState &state) {
        if (event.type == sf::Event::KeyPressed) {
            stateManager.popState();
        }
    }
} // renderer