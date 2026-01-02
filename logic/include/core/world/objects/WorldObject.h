//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_WORLDOBJECT_H
#define AP_PACMAN_WORLDOBJECT_H

#include <type_traits>
#include "core/world/space/Position.h"

namespace logic
{
    class World;

    class WorldObject
    {
        /**
         * The position of the world object.
         * Used for spatial representation in the world.
         */
        Position position;

        /**
         * If true the world will remove this object at the end of this update.
         */
        bool markedForRemoval = false;

    public:
        virtual ~WorldObject() = default;

        /**
         * Type of the events that can be passed to all objects in the world.
         */
        using WorldEventT = int;

        /**
         * @return the position of the world object.
         */
        [[nodiscard]] virtual const Position& getPosition() const;

        /**
         * Set the position of the world object
         * @param position The new position
         */
        virtual void setPosition(const Position& position);

        /**
         * Update the world object.
         * Called on each game update.
         */
        virtual void update(World& world) = 0;

        /**
         * Mark the object to be removed at the end of this update.
         */
        virtual void markForRemoval();

        /**
         * React on worldEvent
         */
        virtual void handleWorldEvent(WorldEventT)
        {
        };

        /**
         * @return Wetter or not the object is marked for removal on the end of this update.
         */
        [[nodiscard]] bool isMarkedForRemoval() const;

        virtual void processCommand(int)
        {
        };
    };

    template <typename T>
    concept IsWorldObject = std::is_base_of_v<WorldObject, T>;
} // logic

#endif //AP_PACMAN_WORLDOBJECT_H
