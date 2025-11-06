//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUUPDATEHANDLER_H
#define AP_PACMAN_MENUUPDATEHANDLER_H

#include "states/IStateUpdateHandler.h"

namespace renderer {
    class IState;

    class MenuUpdateHandler : public IStateUpdateHandler {
    public:
        void update(IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_MENUUPDATEHANDLER_H
