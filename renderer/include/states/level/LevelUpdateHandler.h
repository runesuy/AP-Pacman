//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELUPDATEHANDLER_H
#define AP_PACMAN_LEVELUPDATEHANDLER_H

#include "states/IStateUpdateHandler.h"

namespace renderer {
    class IState;

    class LevelUpdateHandler : public IStateUpdateHandler {
    public:
        void update(IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELUPDATEHANDLER_H
