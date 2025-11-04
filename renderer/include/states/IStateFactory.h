//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_ISTATEFACTORY_H
#define AP_PACMAN_ISTATEFACTORY_H

#include "IState.h"
#include "menu/MenuState.h"

namespace renderer {

    class IStateFactory {
    public:
        virtual std::unique_ptr<MenuState> createMenuState()=0;
    };

} // renderer

#endif //AP_PACMAN_ISTATEFACTORY_H
