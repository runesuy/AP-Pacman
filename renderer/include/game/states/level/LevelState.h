//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELSTATE_H
#define AP_PACMAN_LEVELSTATE_H

#include "core/states/DelegatingState.h"
#include "core/world/World.h"
#include "core/world/WorldView.h"

namespace renderer {

    /**
     * State representing the main gameplay level.
     * Loads a map on the screen and lets player play the game.
     */
    class LevelState : public DelegatingState<LevelState> {
        std::unique_ptr<logic::World> _world;
        std::shared_ptr<WorldView> _worldView;

    public:
        LevelState(std::unique_ptr<IStateUpdateHandler<LevelState>> &&updateHandler, std::unique_ptr<IStateInputHandler<LevelState>> &&inputHandler,
                   std::unique_ptr<IStateDrawHandler<LevelState>> &&drawHandler);

        std::unique_ptr<logic::World> &getWorld();

        [[nodiscard]] const std::shared_ptr<WorldView> &getWorldView() const;

    };

} // renderer

#endif //AP_PACMAN_LEVELSTATE_H
