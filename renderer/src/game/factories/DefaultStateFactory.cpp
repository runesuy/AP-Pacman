//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/DefaultStateFactory.h"
#include "game/states/MenuState.h"
#include "game/states/LevelState.h"

namespace renderer {
    std::unique_ptr<MenuState> DefaultStateFactory::createMenuState() {
        return std::make_unique<MenuState>();
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createLevelState() {
        return std::make_unique<LevelState>();
    }

    std::unique_ptr<PausedState> DefaultStateFactory::createPausedState() {
        return std::make_unique<PausedState>();
    }
} // renderer