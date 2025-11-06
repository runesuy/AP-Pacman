//
// Created by rune-suy on 11/5/25.
//

#include "states/level/LevelState.h"
#include "states/IStateInputHandler.h"

namespace renderer {
    LevelState::LevelState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                           std::unique_ptr<IStateInputHandler> &&inputHandler, std::unique_ptr<logic::IDrawHandler> &&drawHandler)
            : DelegatingState(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler)) {

    }
} // renderer