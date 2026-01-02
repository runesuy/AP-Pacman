//
// Created by runes on 20/11/2025.
//

#include "game/entities/controllers/ManhattanPredictGhostController.h"

namespace logic
{
    void ManhattanPredictGhostController::update(World& world, GhostModel& entity)
    {
        const auto player = world.getObjectsOfType<PlayerModel>().at(0);
        if (!player)
        {
            std::cerr << "No Player Found [ManhattanFollowGhostController::update]" << std::endl;
        }
        // calculate position in front of player
        const auto targetPosition = _calculatePositionInFrontOneStep(
            *player, world.getConfig().getTileMap().getTileSize());
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) && entity.getMode() == GhostModel::CHASE
            && (isAtIntersectionOrDeadEnd(world, entity) || entity.getDirection() == NONE))
        {
            entity.setRequestedDirection(
                navigationAgent->getNavigationDirection(entity.getPosition(), targetPosition, world, {
                                                            getOppositeDirection(entity.getDirection())
                                                        }));
        }
        GhostController::update(world, entity);
    }

    void ManhattanPredictGhostController::processCommand(int command, GhostModel& entity)
    {
    }

    void ManhattanPredictGhostController::onCollision(GhostModel& entity, const SizedWorldObject& other, World& world)
    {
        GhostController::onCollision(entity, other, world);
    }
} // logic
