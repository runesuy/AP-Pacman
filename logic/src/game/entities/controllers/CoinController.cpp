//
// Created by rune-suy on 11/9/25.
//

#include "game/entities/controllers/CoinController.h"

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
        CollectableController::onCollision(entity, other, world);
        entity.updateObservers();
    }
} // logic
