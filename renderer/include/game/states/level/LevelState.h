//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELSTATE_H
#define AP_PACMAN_LEVELSTATE_H

#include "core/states/DelegatingState.h"
#include "core/world/World.h"
#include "core/drawable/DrawCollection.h"

namespace renderer {

    /**
     * State representing the main gameplay level.
     * Loads a map on the screen and lets player play the game.
     */
    class LevelState : public DelegatingState {
        std::unique_ptr<logic::World> _world;
        DrawCollection _drawCollection;
    public:
        LevelState(std::unique_ptr<IStateUpdateHandler> &&updateHandler, std::unique_ptr<IStateInputHandler> &&inputHandler,
                   std::unique_ptr<IDrawHandler> &&drawHandler);


    };

} // renderer

#endif //AP_PACMAN_LEVELSTATE_H
