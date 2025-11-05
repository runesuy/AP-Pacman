//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_ISTATEFACTORY_H
#define AP_PACMAN_ISTATEFACTORY_H

#include "IState.h"

namespace renderer {
    class MenuState;
    class LevelState;
    class IStateFactory {
    public:
        virtual std::unique_ptr<MenuState> createMenuState()=0;

        virtual std::unique_ptr<LevelState> createLevelState()=0;
    };

} // renderer

#endif //AP_PACMAN_ISTATEFACTORY_H
