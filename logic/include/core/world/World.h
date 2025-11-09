//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_WORLD_H
#define AP_PACMAN_WORLD_H

#include "core/entity/IEntityFactory.h"
#include "WorldObject.h"
#include "core/config/IConfig.h"
#include <vector>

namespace logic {
    class World : public Observable<World> {

        /**
         * Configuration reference for all logical settings and factories.
         */
        const IConfig& config;

        /**
         * All objects present in the world.
         * Updated on update.
         */
        std::vector<std::shared_ptr<WorldObject>> objects;

        void _handleCollisions();

        void _removeMarkedObjects();
    public:
        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(const IConfig& config);

        /**
         * Update all objects in the world.
         */
        void update();

        /**
         * Get the configuration reference.
         * @return
         */
        [[nodiscard]] const IConfig &getConfig() const;

        /**
         * Add an object to the world.
         * @param object
         */
        void addObject(const std::shared_ptr<WorldObject>& object);

        void removeObject(const WorldObject& object);

        template<typename Target>
        void sendCommandTo(EntityCommand command) {
            for (const auto& object : objects) {
                auto target = std::dynamic_pointer_cast<Target>(object);
                if (target) {
                    target->processCommand(command);
                }
            }
        };
    };

} // logic

#endif //AP_PACMAN_WORLD_H
