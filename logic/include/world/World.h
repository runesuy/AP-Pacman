//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_WORLD_H
#define AP_PACMAN_WORLD_H

#include "entity/IEntityFactory.h"
#include "WorldObject.h"
#include "IConfig.h"
#include <vector>

namespace logic {
    class World {
        IConfig& config;
        std::vector<std::shared_ptr<WorldObject>> objects;
    public:
        explicit World(IConfig& config);
        void update();

        [[nodiscard]] IConfig &getConfig() const;

        void addObject(const std::shared_ptr<WorldObject>& object);
    };

} // logic

#endif //AP_PACMAN_WORLD_H
