//
// Created by rune-suy on 11/8/25.
//

#include "core/world/objects/CollisionHandler.h"
#include "core/world/objects/SizedWorldObject.h"

namespace logic
{
    void CollisionHandler::handleCollisions(std::vector<std::shared_ptr<WorldObject>>& objects, World& world)
    {
        for (auto& objectA : objects)
        {
            // check if objectA is EntityModel
            // since only SizedWorldObjects have colliders, dynamic casts are used here to call the appropriate methods
            // I could use a separate list of SizedWorldObjects to avoid dynamic casting here, but that would add complexity elsewhere
            // therefore i think dynamic_casts are appropriate here.
            auto sizedObjectA = std::dynamic_pointer_cast<SizedWorldObject>(objectA);
            if (!sizedObjectA)
            {
                continue;
            }
            for (auto& objectB : objects)
            {
                auto sizedObjectB = std::dynamic_pointer_cast<SizedWorldObject>(objectB);
                if (!sizedObjectB || objectA == objectB)
                {
                    continue;
                }
                handleCollision(sizedObjectA, sizedObjectB, world);
            }
        }
    }

    void CollisionHandler::handleCollision(const std::shared_ptr<SizedWorldObject>& objectA,
                                           const std::shared_ptr<SizedWorldObject>& objectB, World& world)
    {
        const Position posA = objectA->getPosition();
        const Size sizeA = objectA->getSize();
        const Position posB = objectB->getPosition();
        const Size sizeB = objectB->getSize();

        const bool overlapX = posA.getX() < posB.getX() + sizeB.getX() / 2 && posA.getX() + sizeA.getX() / 2 > posB.getX();
        if (const bool overlapY = posA.getY() < posB.getY() + sizeB.getY() / 2 && posA.getY() + sizeA.getY() / 2 > posB.getY(); overlapX && overlapY)
        {
            objectA->onCollision(*objectB, world);
            //objectB->onCollision(*objectA); NOT called because of double handling
        }
    }
} // logic
