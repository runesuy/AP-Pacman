//
// Created by runes on 27/11/2025.
//

#include "game/states/paused/PausedState.h"

namespace renderer {
    PausedState::PausedState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                             std::unique_ptr<IStateInputHandler> &&inputHandler,
                             std::unique_ptr<IStateDrawHandler> &&drawHandler) :
            DelegatingState(std::move(updateHandler),std::move(inputHandler), std::move(drawHandler)) {

    }
} // renderer