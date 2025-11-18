//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/controllers/RandomNavGhostController.h"
#include "core/utils/Random.h"

void logic::RandomNavGhostController::processCommand(logic::EntityCommand command, logic::GhostModel &entity) {

}

void logic::RandomNavGhostController::onCollision(GhostModel &entity, const SizedWorldObject &other) {

}

void logic::RandomNavGhostController::update(logic::World &world, logic::GhostModel &entity) {
    GhostController::update(world, entity);
    if (entity.getDirection() == Direction::NONE && entity.getMode() != GhostModel::WAITING) {
        onIsStationary(world, entity);
    }
}

void logic::RandomNavGhostController::onWallCollision(logic::World &world, logic::GhostModel &entity) {
    // set requested direction to a random direction
    onIsStationary(world, entity);
}

std::vector<logic::Direction>
logic::RandomNavGhostController::getViableDirections(const logic::World &world, const logic::GhostModel &entity) {
    std::vector<Direction> viableDirections;
    for (Direction dir : {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT}) {
        TileMap::TileType tileInDirection = getTileInDirection(world, entity, dir);
        if (tileInDirection != TileMap::TileType::WALL) {
            viableDirections.push_back(dir);
        }
    }
    return viableDirections;
}

void logic::RandomNavGhostController::onIsStationary(logic::World &world, logic::GhostModel &entity) {
    std::vector<Direction> viableDirections = getViableDirections(world, entity);
    if (!viableDirections.empty()) {
        Direction randomDirection = viableDirections[Random::getInstance()->getIntInRange(0, static_cast<int>(viableDirections.size()) - 1)];
        entity.setRequestedDirection(randomDirection);
    }
}
