//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_WORLDOBJECT_H
#define AP_PACMAN_WORLDOBJECT_H

#include "core/world/space/Position.h"

namespace logic {
    class World;

    class WorldObject {
        /**
         * The position of the world object.
         * Used for spatial representation in the world.
         */
        Position position;

        bool markedForRemoval = false;
    public:
        /**
         * @return the position of the world object
         */
        [[nodiscard]] virtual const Position & getPosition() const;

        /**
         * Set the position of the world object
         * @param position The new position
         */
        virtual void setPosition(const Position& position);

        /**
         * Update the world object.
         * Called on each game update.
         */
        virtual void update(World &world) = 0;

        virtual void markForRemoval();

        using WorldEventT = int;
        virtual void handleWorldEvent(WorldEventT){};

        bool isMarkedForRemoval() const;
    };

} // logic

#endif //AP_PACMAN_WORLDOBJECT_H
