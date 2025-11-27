//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/DefaultStateFactory.h"
#include "game/states/menu/MenuDrawHandler.h"
#include "game/states/menu/MenuUpdateHandler.h"
#include "game/states/menu/MenuInputHandler.h"
#include "game/states/level/LevelUpdateHandler.h"
#include "game/states/level/LevelInputHandler.h"
#include "game/states/level/LevelDrawHandler.h"
#include "game/states/menu/MenuState.h"
#include "game/states/level/LevelState.h"
#include "game/states/paused/PausedStateDrawHandler.h"
#include "game/states/paused/PausedStateUpdateHandler.h"
#include "game/states/paused/PausedStateInputHandler.h"

namespace renderer {
    std::unique_ptr<MenuState> DefaultStateFactory::createMenuState() {
        std::unique_ptr<MenuUpdateHandler> updateHandler = std::make_unique<MenuUpdateHandler>();
        std::unique_ptr<MenuInputHandler> inputHandler =  std::make_unique<MenuInputHandler>();
        std::unique_ptr<MenuDrawHandler> drawHandler =  std::make_unique<MenuDrawHandler>();
        return std::make_unique<MenuState>(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler));
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createLevelState() {
        auto updateHandler = std::make_unique<LevelUpdateHandler>();
        auto inputHandler =  std::make_unique<LevelInputHandler>();
        auto drawHandler =  std::make_unique<LevelDrawHandler>();
        return std::make_unique<LevelState>(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler));
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createPausedState() {
        auto updateHandler = std::make_unique<PausedStateUpdateHandler>();
        auto inputHandler =  std::make_unique<PausedStateInputHandler>();
        auto drawHandler =  std::make_unique<PausedStateDrawHandler>();
        return std::make_unique<LevelState>(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler));
    }
} // renderer