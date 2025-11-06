//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ISTATEUPDATEHANDLER_H
#define AP_PACMAN_ISTATEUPDATEHANDLER_H
#include "core/IUpdateHandler.h"

namespace renderer {
    class IState;

    class IStateUpdateHandler : public logic::IUpdateHandler {
    public:
        virtual void update(IState& state) = 0;
        void update() override {};
    };

} // renderer

#endif //AP_PACMAN_ISTATEUPDATEHANDLER_H
