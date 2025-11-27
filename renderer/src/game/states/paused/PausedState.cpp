//
// Created by runes on 27/11/2025.
//

#include "game/states/paused/PausedState.h"

namespace renderer {
    PausedState::PausedState(std::unique_ptr<IStateUpdateHandler<PausedState>> &&updateHandler,
                             std::unique_ptr<IStateInputHandler<PausedState>> &&inputHandler,
                             std::unique_ptr<IStateDrawHandler<PausedState>> &&drawHandler) :
            DelegatingState(std::move(updateHandler),std::move(inputHandler), std::move(drawHandler)) {

    }
} // renderer