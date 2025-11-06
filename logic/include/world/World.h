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

        /**
         * Configuration reference for all logical settings and factories.
         */
        IConfig& config;

        /**
         * All objects present in the world.
         * Updated on update.
         */
        std::vector<std::shared_ptr<WorldObject>> objects;
    public:
        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(IConfig& config);

        /**
         * Update all objects in the world.
         */
        void update();

        /**
         * Get the configuration reference.
         * @return
         */
        [[nodiscard]] IConfig &getConfig() const;

        /**
         * Add an object to the world.
         * @param object
         */
        void addObject(const std::shared_ptr<WorldObject>& object);
    };

} // logic

#endif //AP_PACMAN_WORLD_H
