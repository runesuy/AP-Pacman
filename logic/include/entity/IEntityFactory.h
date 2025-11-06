//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IENTITYFACTORY_H
#define AP_PACMAN_IENTITYFACTORY_H

#include "WallModel.h"

namespace logic {
    class IEntityFactory {
    public:
        virtual ~IEntityFactory() = default;

        virtual std::shared_ptr<WallModel> createWallModel() = 0;
    };
}


#endif //AP_PACMAN_IENTITYFACTORY_H
