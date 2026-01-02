//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/DefaultStateFactory.h"
#include "game/states/MenuState.h"
#include "game/states/LevelState.h"

namespace renderer
{
    std::unique_ptr<MenuState> DefaultStateFactory::createMenuState()
    {
        return std::make_unique<MenuState>();
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createLevelState()
    {
        return std::make_unique<LevelState>();
    }

    std::unique_ptr<LevelState> DefaultStateFactory::createLevelState(
        const std::shared_ptr<logic::Score>& passToNextLevel)
    {
        return std::make_unique<LevelState>(passToNextLevel);
    }

    std::unique_ptr<PausedState> DefaultStateFactory::createPausedState()
    {
        return std::make_unique<PausedState>();
    }

    std::unique_ptr<GameOverState> DefaultStateFactory::createGameOverState(
        const std::shared_ptr<logic::Score>& passToNextLevel)
    {
        return std::make_unique<GameOverState>(passToNextLevel);
    }

    std::unique_ptr<VictoryState> DefaultStateFactory::createVictoryState(
        const std::shared_ptr<logic::Score>& passToNextLevel)
    {
        return std::make_unique<VictoryState>(passToNextLevel);
    }
} // renderer
