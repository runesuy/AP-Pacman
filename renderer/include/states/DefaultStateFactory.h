//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DEFAULTSTATEFACTORY_H
#define AP_PACMAN_DEFAULTSTATEFACTORY_H

#include "IStateFactory.h"

namespace renderer {

    class DefaultStateFactory : public IStateFactory {
    public:
        std::unique_ptr<MenuState> createMenuState() override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTSTATEFACTORY_H
