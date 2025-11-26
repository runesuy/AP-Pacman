//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_SIZEDWORLDOBJECT_H
#define AP_PACMAN_SIZEDWORLDOBJECT_H
#include "WorldObject.h"
#include "core/world/space/Size.h"

namespace logic {

    /**
     * A world object containing a size and able to handle collisions.
     * The hitbox is defined by the size and position of the object, with the position in the middle of the resulting rectangle.
     */
    class SizedWorldObject : public WorldObject{
        /**
         * The size of the object.
         * Used as hitbox for collision handling.
         */
        Size size={0,0};

    public:
        /**
         * Typed used for identifying the object during collision handling to avoid expensive casts;
         */
        using CollisionTypeT=int;

        /**
         * Sets the size of the object.
         * The size represents the hitbox of the object.
         * @param size
         */
        virtual void setSize(const Size& size);

        /**
         * @return The size of the object.
         * The size represents the hitbox of the object.
         */
        [[nodiscard]] Size getSize() const;

        /**
         * Handle a collision from this to the other.
         * @param other
         */
        virtual void onCollision(const SizedWorldObject &other, World &world) {};

        /**
        * Return the ID type for collisions.
        * Can be used to identify the other colliding object.
        * @return -1 by default.
        */
        [[nodiscard]] virtual CollisionTypeT getCollisionType() const {return -1;};
    };

} // logic

#endif //AP_PACMAN_SIZEDWORLDOBJECT_H
