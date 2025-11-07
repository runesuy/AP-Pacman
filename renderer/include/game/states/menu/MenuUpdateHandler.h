//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUUPDATEHANDLER_H
#define AP_PACMAN_MENUUPDATEHANDLER_H

#include "core/states/IStateUpdateHandler.h"

namespace renderer {
    class IState;

    /**
     * Update handler for the MenuState, managing updates specific to the main menu.
     */
    class MenuUpdateHandler : public IStateUpdateHandler {
    public:
        void update(IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_MENUUPDATEHANDLER_H
