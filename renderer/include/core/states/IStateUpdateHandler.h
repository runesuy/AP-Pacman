//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ISTATEUPDATEHANDLER_H
#define AP_PACMAN_ISTATEUPDATEHANDLER_H
#include "core/handlers/IUpdateHandler.h"

namespace renderer {
    class IState;

    /**
     * Interface for handling updates specific to a game state.
     */
    template<typename DerivedState>
    class IStateUpdateHandler : public logic::IUpdateHandler {
    public:
        virtual void update(DerivedState& state) = 0;
        void update() override {};
    };

} // renderer

#endif //AP_PACMAN_ISTATEUPDATEHANDLER_H
