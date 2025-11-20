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

    class CollisionHandler {
    public:
        /**
         * Handle collisions between objects of the list.
         * @note Only SizedWorldObjects have collisions.
         * @param objects List of objects.
         */
        static void handleCollisions(std::vector<std::shared_ptr<WorldObject>> &objects, World &world);

        /**
         * Handle a collision from object a to object b.
         * @param objectA
         * @param objectB
         */
        static void handleCollision(const std::shared_ptr<SizedWorldObject> &objectA,
                                    const std::shared_ptr<SizedWorldObject> &objectB, World &world);
    };

} // logic

#endif //AP_PACMAN_COLLISIONHANDLER_H
