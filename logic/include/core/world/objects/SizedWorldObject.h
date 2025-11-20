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
     */
    class SizedWorldObject : public WorldObject{
        /**
         * The size of the object.
         */
        Size size={0,0};

    public:
        /**
         * Sets the size of the object.
         * @param size
         */
        virtual void setSize(const Size& size);

        /**
         * @return The size of the object.
         */
        [[nodiscard]] Size getSize() const;

        /**
         * Handle a collision with other.
         * @param other
         */
        virtual void onCollision(const SizedWorldObject &other) {};


        using CollisionType=int;

        /**
        * Return the ID type for collisions.
        * Can be used to identify the other colliding object.
        * @return -1 by default.
        */
        [[nodiscard]] virtual CollisionType getCollisionType() const {return -1;};
    };

} // logic

#endif //AP_PACMAN_SIZEDWORLDOBJECT_H
