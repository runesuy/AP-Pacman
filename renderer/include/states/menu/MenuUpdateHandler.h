//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_MENUUPDATEHANDLER_H
#define AP_PACMAN_MENUUPDATEHANDLER_H

#include "../../core/IUpdateHandler.h"

namespace renderer {

    class MenuUpdateHandler : public IUpdateHandler {
    public:
        void update() override;
    };

} // renderer

#endif //AP_PACMAN_MENUUPDATEHANDLER_H
