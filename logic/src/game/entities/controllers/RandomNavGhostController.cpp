//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/controllers/RandomNavGhostController.h"
#include "core/utils/Random.h"

void logic::RandomNavGhostController::processCommand(EntityCommand command, GhostModel& entity)
{
}

void logic::RandomNavGhostController::onCollision(GhostModel& entity, const SizedWorldObject& other, World& world)
{
    GhostController::onCollision(entity, other, world);
}

void logic::RandomNavGhostController::update(World& world, GhostModel& entity)
{
    GhostController::update(world, entity);
    if (entity.getMode() == GhostModel::WAITING) return;
    if (entity.getDirection() == NONE)
    {
        chooseDirection(world, entity);
    }
    auto tilemap = world.getConfig().getTileMap();
    if (world.getConfig().getTileMap().getViableDirections(world, entity.getPosition()).size() > 2 && !get<0>(
        _isPastOrOnCenter(world, entity, entity.getDirection())))
    {
        chooseDirection(world, entity);
    }
}

void logic::RandomNavGhostController::onWallCollision(World& world, GhostModel& entity)
{
    // set requested direction to a random direction
    chooseDirection(world, entity);
}

void logic::RandomNavGhostController::chooseDirection(World& world, GhostModel& entity)
{
    if (const bool change = Random::getInstance()->getIntInRange(0, 1); !change) return;
    std::vector<Direction> viableDirections = world.getConfig().getTileMap().getViableDirections(
        world, entity.getPosition());
    if (!viableDirections.empty())
    {
        // if more than one direction to choose from, remove opposite of currentDirection from viableDirections
        if (viableDirections.size() > 1)
        {
            erase(viableDirections, getOppositeDirection(entity.getDirection()));
        }

        const Direction randomDirection = viableDirections[Random::getInstance()->getIntInRange(
            0, static_cast<int>(viableDirections.size()) - 1)];
        entity.setRequestedDirection(randomDirection);
    }
}
