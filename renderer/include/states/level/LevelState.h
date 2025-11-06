//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELSTATE_H
#define AP_PACMAN_LEVELSTATE_H

#include "states/DelegatingState.h"
#include "world/World.h"
#include "drawable/DrawCollection.h"

namespace renderer {

    class LevelState : public DelegatingState {
        std::unique_ptr<logic::World> _world;
        DrawCollection _drawCollection;
    public:
        LevelState(std::unique_ptr<IStateUpdateHandler> &&updateHandler, std::unique_ptr<IStateInputHandler> &&inputHandler,
                   std::unique_ptr<logic::IDrawHandler> &&drawHandler);


    };

} // renderer

#endif //AP_PACMAN_LEVELSTATE_H
