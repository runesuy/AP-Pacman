//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COLLISIONHANDLER_H
#define AP_PACMAN_COLLISIONHANDLER_H
#include <vector>
#include <memory>
#include "core/world/WorldObject.h"
#include "core/world/SizedWorldObject.h"

namespace logic {

    class CollisionHandler {
    public:
        static void handleCollisions(std::vector<std::shared_ptr<WorldObject>>& objects);

        static void handleCollision(const std::shared_ptr<SizedWorldObject>& objectA,
                                    const std::shared_ptr<SizedWorldObject>& objectB);
    };

} // logic

#endif //AP_PACMAN_COLLISIONHANDLER_H
