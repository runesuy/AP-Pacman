//
// Created by rune-suy on 11/5/25.
//

#include "game/states/level/LevelDrawHandler.h"
#include "game/states/level/LevelState.h"

namespace renderer {

    void LevelDrawHandler::draw(sf::RenderWindow &window, LevelState &state, StateManager& stateManager) {
        auto& levelState = dynamic_cast<LevelState&>(state);
        levelState.getWorldView()->draw(window);
    }
} // renderer