//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_WORLD_H
#define AP_PACMAN_WORLD_H

#include "entity/IEntityFactory.h"

namespace logic {
    class World {
        std::unique_ptr<IEntityFactory> entityFactory;
    public:
        explicit World(std::unique_ptr<IEntityFactory> entityFactory);
        void update();
    };

} // logic

#endif //AP_PACMAN_WORLD_H
