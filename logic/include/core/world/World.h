//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_WORLD_H
#define AP_PACMAN_WORLD_H

#include "core/entity/IEntityFactory.h"
#include "core/world/objects/WorldObject.h"
#include "core/config/IConfig.h"
#include "Score.h"
#include <vector>
#include "LifeCounter.h"

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

        std::shared_ptr<Score> score = std::make_shared<Score>();

        std::shared_ptr<LifeCounter> lifeCounter = std::make_shared<LifeCounter>();

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

        void sendWorldEvent(WorldObject::WorldEventT event);

        /**
         * Add an object to the world.
         * If the object is a PlayerModel, attach the Score as an observer.
         * @param object
         */
        void addObject(const std::shared_ptr<WorldObject>& object);

        void removeObject(const WorldObject& object);

        template<typename Target>
        void sendCommandTo(EntityCommand command);

        template<typename Target>
        [[nodiscard]] std::vector<std::shared_ptr<Target>> getObjectsOfType() const;

        [[nodiscard]] const Score &getScore() const;

        Score &getScore() ;

        [[nodiscard]] bool levelComplete() const;
    };



    //--------------- Implementation--------------------//

    template<typename Target>
    std::vector<std::shared_ptr<Target>> World::getObjectsOfType() const {
        std::vector<std::shared_ptr<Target>> result;
        for (const auto& object : objects) {
            auto derived = std::dynamic_pointer_cast<Target>(object);
            if (derived) result.push_back(derived);
        }
        return  result;
    }

    template<typename Target>
    void World::sendCommandTo(logic::EntityCommand command) {
        for (const auto& object : objects) {
            auto target = std::dynamic_pointer_cast<Target>(object);
            if (target) {
                target->processCommand(command);
            }
        }
    }

} // logic

#endif //AP_PACMAN_WORLD_H
