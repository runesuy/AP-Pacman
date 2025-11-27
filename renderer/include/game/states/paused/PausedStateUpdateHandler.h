//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
#define AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
#include "core/states/IStateUpdateHandler.h"
#include "PausedState.h"

namespace renderer {

    class PausedStateUpdateHandler : public IStateUpdateHandler<PausedState> {
    public:
        void update(PausedState &state) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
