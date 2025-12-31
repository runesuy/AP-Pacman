//
// Created by runes on 18/11/2025.
//

#include "game/entities/controllers/ManhattanFollowGhostController.h"

namespace logic
{
    void ManhattanFollowGhostController::update(World& world, GhostModel& entity)
    {
        const auto player = world.getObjectsOfType<PlayerModel>().at(0);
        if (!player)
        {
            std::cerr << "No Player Found [ManhattanFollowGhostController::update]" << std::endl;
        }
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) && entity.getMode() == GhostModel::CHASE
            && (isAtIntersectionOrDeadEnd(world, entity) || entity.getDirection() == NONE))
        {
            entity.setRequestedDirection(
                navigationAgent->getNavigationDirection(entity.getPosition(), player->getPosition(), world, {
                                                            getOppositeDirection(entity.getDirection())
                                                        }));
        }

        GhostController::update(world, entity);
    }

    void ManhattanFollowGhostController::processCommand(EntityCommand command, GhostModel& entity)
    {
    }

    void ManhattanFollowGhostController::onCollision(GhostModel& entity, const SizedWorldObject& other, World& world)
    {
        GhostController::onCollision(entity, other, world);
    }
} // logic
