//
// Created by rune-suy on 11/5/25.
//

#include "game/states/level/LevelState.h"

#include <memory>
#include "core/states/IStateInputHandler.h"
#include "game/Game.h"
#include "game/factories/DefaultEntityFactory.h"

namespace renderer {
    LevelState::LevelState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                           std::unique_ptr<IStateInputHandler> &&inputHandler, std::unique_ptr<IStateDrawHandler> &&drawHandler)
            : DelegatingState(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler)) {

        auto &logicConfig = Game::getInstance()->getAppConfig().getLogicConfig();
        auto entityFactory = logicConfig.getEntityFactory();
        auto defaultFactory = std::dynamic_pointer_cast<DefaultEntityFactory>(entityFactory);
        _worldView = std::make_shared<WorldView>();
        if (defaultFactory) {
            defaultFactory->setViewTarget(_worldView);
        }
        _world = std::make_unique<logic::World>(logicConfig);
        _world->addObserver(_worldView);

    }

    std::unique_ptr<logic::World> &LevelState::getWorld() {
        return _world;
    }

    const std::shared_ptr<WorldView> &LevelState::getWorldView() const {
        return _worldView;
    }
} // renderer