//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DEFAULTSTATEFACTORY_H
#define AP_PACMAN_DEFAULTSTATEFACTORY_H

#include <memory>
#include "states/IStateFactory.h"

namespace renderer {
    class MenuState;
    class LevelState;

    class DefaultStateFactory : public IStateFactory {
    public:
        std::unique_ptr<MenuState> createMenuState() override;

        std::unique_ptr<LevelState> createLevelState() override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTSTATEFACTORY_H
