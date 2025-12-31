//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_ISTATEFACTORY_H
#define AP_PACMAN_ISTATEFACTORY_H

#include "game/states/GameOverState.h"
#include "game/states/PausedState.h"
#include "game/states/VictoryState.h"

namespace renderer
{
    class MenuState;
    class LevelState;

    /**
     * Interface for state factory, responsible for creating different game states.
     * Interchangeable using config system.
     */
    class IStateFactory
    {
    public:
        virtual ~IStateFactory() = default;

        /**
         * Create a new MenuState instance.
         * @return A unique pointer to a new MenuState instance.
         */
        virtual std::unique_ptr<MenuState> createMenuState() =0;

        /**
         * Create a new LevelState instance.
         * @return
         */
        virtual std::unique_ptr<LevelState> createLevelState() =0;

        /**
         * Create a new LevelState instance with score passed from previous level.
         * @param passToNextLevel
         * @return
         */
        virtual std::unique_ptr<LevelState> createLevelState(const std::shared_ptr<logic::Score>& passToNextLevel) =0;

        /**
         * Create a new PausedState instance.
         * @return
         */
        virtual std::unique_ptr<PausedState> createPausedState() =0;

        /**
         * Create a new VictoryState instance.
         * @return
         */
        virtual std::unique_ptr<VictoryState> createVictoryState(const std::shared_ptr<logic::Score>& passToNextLevel) =0;

        /**
         * Create a new GameOverState instance.
         * @return
         */
        virtual std::unique_ptr<GameOverState> createGameOverState(const std::shared_ptr<logic::Score>& passToNextLevel) =0;
    };
} // renderer

#endif //AP_PACMAN_ISTATEFACTORY_H
