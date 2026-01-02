//
// Created by rune-suy on 11/14/25.
//

#include "game/entities/controllers/GhostController.h"
#include "game/WorldEvents.h"
#include "game/entities/ObserverEvents.h"

namespace logic
{
    void GhostController::update(World& world, GhostModel& entity)
    {
        MovingEntityController::update(world, entity);
        if (entity.getMode() == GhostModel::WAITING)
        {
            if (entity.getStartTimer() < entity.getStartDelay())
                entity.setStartTimer(entity.getStartTimer() + Stopwatch::getInstance()->getDeltaTime());
            else
            {
                entity.setMode(GhostModel::CHASE);
                entity.setStartTimer(0);
            }

            if (entity.getDirection() != NONE)
            {
                entity.setRequestedDirection(NONE);
            }
        }

        if (entity.getMode() == GhostModel::FRIGHTENED)
        {
            if (justChangedToFrightened)
            {
                entity.setDirection(
                    frightenedNavigationAgent->getNavigationDirection(entity.getPosition(), entity.getSpawnPosition(),
                                                                      world, {}));
                justChangedToFrightened = false;
            }

            if (entity.getFrightenedTimer() < entity.getFrightenedDuration())
                entity.setFrightenedTimer(entity.getFrightenedTimer() + Stopwatch::getInstance()->getDeltaTime());
            else
            {
                entity.setFrightenedTimer(0);
                entity.setMode(GhostModel::CHASE);
            }
        }

        // returning mode
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) && entity.getMode() ==
            GhostModel::RETURNING_HOME)
        {
            if (entity.getDirection() == NONE || isAtIntersectionOrDeadEnd(world, entity))
            {
                entity.setRequestedDirection(
                    returnNavigationAgent->getNavigationDirection(entity.getPosition(), entity.getReturnPosition(),
                                                                  world, {
                                                                      getOppositeDirection(entity.getDirection())
                                                                  }));
            }
            const auto& tileMap = world.getConfig().getTileMap();
            if (tileMap.getGridPosition(entity.getPosition()) == tileMap.getGridPosition(entity.getReturnPosition()))
            {
                entity.setMode(GhostModel::CHASE);
            }
        }

        // frightened mode
        if (!get<0>(_isPastCenter(world, entity, entity.getDirection())) &&
            entity.getMode() == GhostModel::FRIGHTENED)
        {
            const auto player = world.getPlayerModel().lock();
            entity.setRequestedDirection(
                frightenedNavigationAgent->getNavigationDirectionAway(entity.getPosition(), player->getPosition(),
                                                                      world, {
                                                                          getOppositeDirection(entity.getDirection())
                                                                      }));
        }
    }

    void GhostController::handleWorldEvent(const WorldObject::WorldEventT event, GhostModel& entity)
    {
        switch (event)
        {
        case (WorldEvents::FRUIT_EATEN_BY_PLAYER):
            {
                if (entity.getMode() == GhostModel::CHASE)
                    entity.setMode(GhostModel::FRIGHTENED);
                justChangedToFrightened = true;
                entity.setFrightenedTimer(0);
                break;
            }
        case (WorldEvents::PLAYER_KILLED):
            {
                entity.setPosition(entity.getSpawnPosition());
                entity.setDirection(NONE);
                entity.setFrightenedTimer(0);
                entity.setMode(GhostModel::CHASE);
                break;
            }
        default: break;
        }

    }

    void GhostController::onCollision(GhostModel& entity, const SizedWorldObject& other, World& world)
    {
        if (other.getCollisionType() == PLAYER && entity.getMode() == GhostModel::CHASE)
        {
            world.sendWorldEvent(WorldEvents::PLAYER_KILLED);
        }
        if (other.getCollisionType() == PLAYER && entity.getMode() == GhostModel::FRIGHTENED)
        {
            entity.setMode(GhostModel::RETURNING_HOME);
            world.sendWorldEvent(WorldEvents::PLAYER_GHOST_KILLED);
        }
    }

    bool GhostController::isAtIntersectionOrDeadEnd(const World& world, const GhostModel& entity)
    {
        auto viableDirections = world.getConfig().getTileMap().getViableDirections(world, entity.getPosition());
        return viableDirections.size() != 2 ||
            std::ranges::find(viableDirections, entity.getDirection()) == viableDirections.
            end() ||
            std::ranges::find(viableDirections, getOppositeDirection(entity.getDirection()))
            == viableDirections.end();
    }
} // logic
