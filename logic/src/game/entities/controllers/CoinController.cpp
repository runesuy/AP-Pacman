//
// Created by rune-suy on 11/9/25.
//

#include "game/entities/controllers/CoinController.h"

#include "core/world/World.h"
#include "game/WorldEvents.h"

namespace logic
{
    void CoinController::update(World& world, CoinModel& entity)
    {
    }

    void CoinController::processCommand(int command, CoinModel& entity)
    {
    }

    void CoinController::onCollision(CoinModel& entity, const SizedWorldObject& other, World& world)
    {
        if (other.getCollisionType() == PLAYER)
        {
            world.sendWorldEvent(WorldEvents::COIN_COLLECTED);
        }

        CollectableController::onCollision(entity, other, world);
        entity.updateObservers();
    }
} // logic
