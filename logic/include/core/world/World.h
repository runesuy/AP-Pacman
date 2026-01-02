//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_WORLD_H
#define AP_PACMAN_WORLD_H

#include "core/entity/IEntityFactory.h"
#include "core/world/objects/WorldObject.h"
#include "core/config/ILogicConfig.h"
#include "Score.h"
#include <vector>

namespace logic
{
    /**
     * World is the center of the logic part of the game.
     *
     * update(...) to simulate
     * simulation only starts when the ON_KEY_PRESSED command is sent,
     * and stops on each player death, send ON_KEY_PRESSED again to continue
     */
    class World : public Observable<World>
    {
        /**
         * Configuration reference for all logical settings and factories.
         */
        const ILogicConfig& config;

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

        /**
         * Used for making simulation wait until the pacman makes his first move.
         */
        bool _initialKeyPressed = false;


        void _handleWorldEvent(WorldObject::WorldEventT worldEvent);

    public:
        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(const ILogicConfig& config);

        /**
         * Construct a World with the given configuration.
         * @param config Logic configuration reference.
         */
        explicit World(const ILogicConfig& config, std::shared_ptr<Score> score);

        /**
         * Update all objects in the world.
         */
        void update();

        /**
         * Get the configuration reference.
         * @return
         */
        [[nodiscard]] const ILogicConfig& getConfig() const;

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
        template <IsWorldObject Target>
        void sendCommandTo(int command);

        /**
         * @tparam Target
         * @return A std::vector of all worldObjects of type Target present in the world.
         */
        template <IsWorldObject Target>
        [[nodiscard]] std::vector<std::shared_ptr<Target>> getObjectsOfType() const;

        /**
         * @return The score instance.
         *
         * Score provides score and player life logic.
         */
        [[nodiscard]] const Score& getScore() const;

        /**
         * @return The score instance.
         *
         * Score provides score and player life logic.
         */
        [[nodiscard]] std::shared_ptr<Score>& getScore();


        /**
         * @return true if all coins are collected
         */
        [[nodiscard]] bool levelComplete() const;

        /**
         * @return true the player has no lives left
         */
        [[nodiscard]] bool isGameOver() const;

        using WorldCommandType = int;

        /**
         * Change the world based on the command.
         * @param command
         */
        void receiveCommand(WorldCommandType command);
    };


    //--------------- Implementation--------------------//

    template <IsWorldObject Target>
    std::vector<std::shared_ptr<Target>> World::getObjectsOfType() const
    {
        std::vector<std::shared_ptr<Target>> result;
        for (const auto& object : objects)
        {
            if (auto derived = std::dynamic_pointer_cast<Target>(object)) result.push_back(derived);
        }
        return result;
    }

    template <IsWorldObject Target>
    void World::sendCommandTo(const int command)
    {
        for (const auto& object : objects)
        {
            if (typeid(Target) == typeid(*object))
            {
                object->processCommand(command);
            }
        }
    }
} // logic

#endif //AP_PACMAN_WORLD_H
