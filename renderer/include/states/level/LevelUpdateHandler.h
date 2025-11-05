//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELUPDATEHANDLER_H
#define AP_PACMAN_LEVELUPDATEHANDLER_H

#include "core/IUpdateHandler.h"

namespace renderer {

    class LevelUpdateHandler : public IUpdateHandler {
    public:
        void update() override;
    };

} // renderer

#endif //AP_PACMAN_LEVELUPDATEHANDLER_H
