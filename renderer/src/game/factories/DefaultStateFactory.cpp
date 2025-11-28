//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/DefaultStateFactory.h"
#include "game/states/level/LevelUpdateHandler.h"
#include "game/states/level/LevelInputHandler.h"
#include "game/states/level/LevelDrawHandler.h"
#include "game/states/menu/MenuState.h"
#include "game/states/level/LevelState.h"

namespace renderer {
    std::unique_ptr<MenuState> DefaultStateFactory::createMenuState() {
        return std::make_unique<MenuState>();
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createLevelState() {
        auto updateHandler = std::make_unique<LevelUpdateHandler>();
        auto inputHandler =  std::make_unique<LevelInputHandler>();
        auto drawHandler =  std::make_unique<LevelDrawHandler>();
        return std::make_unique<LevelState>(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler));
    }

    std::unique_ptr<PausedState> DefaultStateFactory::createPausedState() {
        return std::make_unique<PausedState>();
    }
} // renderer