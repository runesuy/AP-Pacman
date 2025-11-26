//
// Created by runes on 20/11/2025.
//

#include "game/entities/controllers/ManhattanPredictGhostController.h"

namespace logic {
    void ManhattanPredictGhostController::update(World &world, GhostModel &entity) {
        auto player = world.getObjectsOfType<PlayerModel>().at(0);
        if (!player) {
            std::cerr << "No Player Found [ManhattanFollowGhostController::update]" << std::endl;
        }
        // calculate position in front of player
        auto targetPosition = _calculatePositionInFrontOneStep(*player, world.getConfig().getTileMap().getTileSize());
        unsigned directionOptions = getViableDirections(world, entity).size();
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) && entity.getMode() == GhostModel::CHASE
        && (isAtIntersectionOrDeadEnd(world, entity) ||entity.getDirection() == NONE)) {
            entity.setRequestedDirection(
                    navigationAgent->getNavigationDirection(entity.getPosition(), targetPosition, world, {
                            getOppositeDirection(entity.getDirection())}));
        }
        GhostController::update(world, entity);
    }

    void ManhattanPredictGhostController::processCommand(EntityCommand command, GhostModel &entity) {

    }

    void ManhattanPredictGhostController::onCollision(GhostModel &entity, const SizedWorldObject &other, World& world) {
        GhostController::onCollision(entity, other, world);
    }

} // logic