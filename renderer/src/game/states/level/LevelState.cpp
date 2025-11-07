//
// Created by rune-suy on 11/5/25.
//

#include "game/states/level/LevelState.h"

#include <memory>
#include "core/states/IStateInputHandler.h"
#include "game/Game.h"

namespace renderer {
    LevelState::LevelState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                           std::unique_ptr<IStateInputHandler> &&inputHandler, std::unique_ptr<IDrawHandler> &&drawHandler)
            : DelegatingState(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler)) {

        auto &logicConfig = Game::getInstance()->getAppConfig().getLogicConfig();
        _world = std::make_unique<logic::World>(logicConfig);
    }
} // renderer