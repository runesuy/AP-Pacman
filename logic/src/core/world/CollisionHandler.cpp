//
// Created by rune-suy on 11/8/25.
//

#include "core/world/CollisionHandler.h"
#include "core/world/SizedWorldObject.h"

namespace logic {
    void CollisionHandler::handleCollisions(std::vector<std::shared_ptr<WorldObject>> &objects) {
        for (auto& objectA : objects) {
            // check if objectA is EntityModel
            auto sizedObjectA = std::dynamic_pointer_cast<SizedWorldObject>(objectA);
            if (!sizedObjectA) {
                continue;
            }
            for (auto& objectB : objects) {
                auto sizedObjectB = std::dynamic_pointer_cast<SizedWorldObject>(objectB);
                if (!sizedObjectB || objectA == objectB) {
                    continue;
                }
                handleCollision(sizedObjectA, sizedObjectB);
            }
        }
    }

    void CollisionHandler::handleCollision(const std::shared_ptr<SizedWorldObject> &objectA,
                                           const std::shared_ptr<SizedWorldObject> &objectB) {

        Position posA = objectA->getPosition();
        Size sizeA = objectA->getSize();
        Position posB = objectB->getPosition();
        Size sizeB = objectB->getSize();

        bool overlapX = posA.getX() < posB.getX() + sizeB.getX()/2 && posA.getX()+ sizeA.getX()/2 > posB.getX();
        bool overlapY = posA.getY() < posB.getY() + sizeB.getY()/2 && posA.getY() + sizeA.getY()/2 > posB.getY();
        if (overlapX && overlapY) {
            objectA->onCollision(*objectB);
            //objectB->onCollision(*objectA); NOT called because of double handling
        }
    }
} // logic