//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
#define AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
#include "core/states/IStateUpdateHandler.h"

namespace renderer {

    class PausedStateUpdateHandler : public IStateUpdateHandler {
    public:
        void update(IState &state) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEUPDATEHANDLER_H
