//
// Created by rune-suy on 11/4/25.
//

#include <iostream>
#include "../../../include/states/menu/MenuInputHandler.h"
#include "Game.h"
#include "states/level/LevelState.h"

namespace renderer {
    void MenuInputHandler::processInput(sf::Event &event, StateManager& stateManager) {
        if (event.type == sf::Event::KeyPressed) {

            std::unique_ptr<LevelState> levelState = Game::getInstance()->getAppConfig().getFactoryCollection().getStateFactory()->createLevelState();
            stateManager.pushState(std::move(levelState));
        }
    }
} // renderer