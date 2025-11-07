//
// Created by rune-suy on 11/4/25.
//

#include <iostream>
#include "game/states/menu/MenuInputHandler.h"
#include "game/Game.h"
#include "game/states/level/LevelState.h"
#include "core/factories/IStateFactory.h"
#include "core/states/IStateUpdateHandler.h"

namespace renderer {
    void MenuInputHandler::processInput(sf::Event &event, StateManager &stateManager, IState &state) {
        if (event.type == sf::Event::KeyPressed) {

            std::unique_ptr<LevelState> levelState = Game::getInstance()->getAppConfig().getFactoryCollection().getStateFactory()->createLevelState();
            stateManager.pushState(std::move(levelState));
        }
    }
} // renderer