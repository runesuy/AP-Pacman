//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATE_H
#define AP_PACMAN_PAUSEDSTATE_H
#include "core/states/DelegatingState.h"

namespace renderer {

    class PausedState  : public DelegatingState {
    public:
        PausedState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                    std::unique_ptr<IStateInputHandler> &&inputHandler,
                    std::unique_ptr<IStateDrawHandler> &&drawHandler);
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATE_H
