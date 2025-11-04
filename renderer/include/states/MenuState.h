//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_MENUSTATE_H
#define AP_PACMAN_MENUSTATE_H

#include "IState.h"

namespace renderer {

    class MenuState : public IState{
        void update() override;
    };

} // renderer

#endif //AP_PACMAN_MENUSTATE_H
