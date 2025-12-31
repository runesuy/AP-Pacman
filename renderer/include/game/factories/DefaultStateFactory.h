//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DEFAULTSTATEFACTORY_H
#define AP_PACMAN_DEFAULTSTATEFACTORY_H

#include <memory>
#include "core/factories/IStateFactory.h"
#include "game/states/PausedState.h"

namespace renderer
{
    class MenuState;
    class LevelState;

    /**
     * A default implementation of the IStateFactory interface.
     * Creates standard game states used in the application.
     */
    class DefaultStateFactory : public IStateFactory
    {
    public:
        std::unique_ptr<MenuState> createMenuState() override;

        std::unique_ptr<LevelState> createLevelState() override;

        std::unique_ptr<LevelState> createLevelState(const std::shared_ptr<logic::Score>& passToNextLevel) override;

        std::unique_ptr<PausedState> createPausedState() override;

        std::unique_ptr<VictoryState> createVictoryState(const std::shared_ptr<logic::Score>& passToNextLevel) override;

        std::unique_ptr<GameOverState> createGameOverState(const std::shared_ptr<logic::Score>& passToNextLevel) override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTSTATEFACTORY_H
