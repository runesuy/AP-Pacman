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

        /**
         * The score tracks player score and lives based on the world and the player.
         */
        std::shared_ptr<Score> score = std::make_shared<Score>();

        /**
         * Let the CollisionHandles handle all collisions between the worldObjects
         * @see CollisionHandler
         */
        void _handleCollisions();

        /**
         * Remove all objects with isMarkedForRemoval==true
         */
        void _removeMarkedObjects();
    public:
        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(const IConfig& config);

        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(const IConfig& config, std::shared_ptr<Score> score);

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
         * Send a world event to all worldObjects in the world.
         * @param event
         */
        void sendWorldEvent(WorldObject::WorldEventT event);

        /**
         * Add an object to the world.
         * If the object is a PlayerModel, attach the Score as an observer.
         * @param object
         */
        void addObject(const std::shared_ptr<WorldObject>& object);

        /**
         * Remove object if present in the worldObjects.
         * @param object
         */
        void removeObject(const WorldObject& object);

        /**
         * Send entityCommand command to all worldObjects of type Target
         * @tparam Target
         * @param command
         */
        template<typename Target>
        void sendCommandTo(EntityCommand command);

        /**
         * @tparam Target
         * @return A std::vector of all worldObjects of type Target present in the world.
         */
        template<typename Target>
        [[nodiscard]] std::vector<std::shared_ptr<Target>> getObjectsOfType() const;

        /**
         * @return The score instance.
         *
         * Score provides score and player life logic.
         */
        [[nodiscard]] const Score &getScore() const;

        /**
         * @return The score instance.
         *
         * Score provides score and player life logic.
         */
        [[nodiscard]] Score &getScore();

        /**
         * @return true if all coins are collected
         */
        [[nodiscard]] bool levelComplete() const;

        /**
         * @return true the player has no lives left
         */
        [[nodiscard]] bool isGameOver() const;
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
