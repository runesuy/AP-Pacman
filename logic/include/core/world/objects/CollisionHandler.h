//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COLLISIONHANDLER_H
#define AP_PACMAN_COLLISIONHANDLER_H
#include <vector>
#include <memory>
#include "WorldObject.h"
#include "SizedWorldObject.h"

namespace logic {
    /**
     * Handles collisions between WorldObjects and calls their onCollision methods when the rectangles given by the
     * position and size of the objects intersect.
     * By default the position sits in the center of the rectangle described above.
     *
     * @note This means only SizedWorldObjects have collisions.
     */
    class CollisionHandler {
    public:
        /**
         * Handle collisions between objects of the list.
         * When the rectangles defined by the size and position of the object intersect, their onCollision method is called.
         * By default the position sits in the middle of this rectangle.
         * @note Only SizedWorldObjects have collisions.
         * @param objects List of objects.
         */
        static void handleCollisions(std::vector<std::shared_ptr<WorldObject> > &objects, World &world);

        /**
         * Handle a collision from object a to object b.
         * Calls the onCollision method in method a with param b.
         * @param objectA
         * @param objectB
         */
        static void handleCollision(const std::shared_ptr<SizedWorldObject> &objectA,
                                    const std::shared_ptr<SizedWorldObject> &objectB, World &world);
    };
} // logic

#endif //AP_PACMAN_COLLISIONHANDLER_H