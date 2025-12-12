//
// Created by rune-suy on 11/14/25.
//

#include "game/entities/controllers/GhostController.h"
#include "game/WorldEvents.h"

namespace logic {
    void GhostController::update(World &world, GhostModel &entity) {
        MovingEntityController::update(world, entity);
        if (entity.getMode() == GhostModel::WAITING) {
            if (entity.getStartTimer() < entity.getStartDelay())
                entity.setStartTimer(entity.getStartTimer() + Stopwatch::getInstance()->getDeltaTime());
            else {
                entity.setMode(GhostModel::CHASE);
                entity.setStartTimer(0);
            }

            if (entity.getDirection() != Direction::NONE) {
                entity.setRequestedDirection(Direction::NONE);
            }
        }

        if (entity.getMode() == GhostModel::FRIGHTENED) {
            if (justChangedToFrightened) {
                entity.setDirection(
                    frightenedNavigationAgent->getNavigationDirection(entity.getPosition(), entity.getSpawnPosition(),
                                                                      world,{}));
                justChangedToFrightened = false;
            }

            if (entity.getFrightenedTimer() < entity.getFrightenedDuration())
                entity.setFrightenedTimer(entity.getFrightenedTimer() + Stopwatch::getInstance()->getDeltaTime());
            else {
                entity.setFrightenedTimer(0);
                entity.setMode(GhostModel::CHASE);
            }
        }

        // returning mode
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) && entity.getMode() ==
            GhostModel::RETURNING_HOME) {
            if (entity.getDirection() == NONE || isAtIntersectionOrDeadEnd(world, entity)) {
                entity.setRequestedDirection(
                    returnNavigationAgent->getNavigationDirection(entity.getPosition(), entity.getReturnPosition(),
                                                                  world, {
                                                                      getOppositeDirection(entity.getDirection())
                                                                  }));
            }
            const auto &tileMap = world.getConfig().getTileMap();
            if (tileMap.getGridPosition(entity.getPosition()) == tileMap.getGridPosition(entity.getReturnPosition())) {
                entity.setMode(GhostModel::CHASE);
            }
        }

        // frightened mode
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) &&
            entity.getMode() == GhostModel::FRIGHTENED) {
            auto player = world.getObjectsOfType<PlayerModel>().at(0);
            entity.setRequestedDirection(
                frightenedNavigationAgent->getNavigationDirectionAway(entity.getPosition(), player->getPosition(),
                                                                      world, {
                                                                          getOppositeDirection(entity.getDirection())
                                                                      }));
        }
    }

    void GhostController::handleWorldEvent(WorldObject::WorldEventT event, GhostModel &entity) {
        switch (event) {
            default: {
            }
            case (FRUIT_EATEN_BY_PLAYER): {
                if (entity.getMode() == GhostModel::CHASE)
                    entity.setMode(GhostModel::FRIGHTENED);
                justChangedToFrightened = true;
                break;
            }
            case (WorldEvent::PLAYER_KILLED_W): {
                entity.setPosition(entity.getSpawnPosition());
                entity.setDirection(NONE);
                entity.setFrightenedTimer(0);
                entity.setMode(GhostModel::CHASE);
                break;
            }
        }
    }

    void GhostController::onCollision(GhostModel &entity, const SizedWorldObject &other, World &world) {
        if (other.getCollisionType() == PLAYER && entity.getMode() == GhostModel::FRIGHTENED) {
            entity.setMode(GhostModel::RETURNING_HOME);
        }
    }

    bool GhostController::isAtIntersectionOrDeadEnd(const World &world, const GhostModel &entity) {
        auto viableDirections = world.getConfig().getTileMap().getViableDirections(world, entity.getPosition());
        return viableDirections.size() != 2 ||
               std::find(viableDirections.begin(), viableDirections.end(), entity.getDirection()) == viableDirections.
               end() ||
               std::find(viableDirections.begin(), viableDirections.end(), getOppositeDirection(entity.getDirection()))
               == viableDirections.end();
    }
} // logic
