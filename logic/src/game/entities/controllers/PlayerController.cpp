//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/controllers/PlayerController.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"
#include "core/world/World.h"
#include <typeinfo>
#include "game/entities/models/CollisionTypes.h"
#include "game/WorldEvents.h"
#include "game/entities/ObserverEvents.h"

namespace logic
{
    void PlayerController::processCommand(EntityCommand command, PlayerModel& entity)
    {
        switch (command)
        {
        case EntityCommand::TURN_LEFT:
            entity.setRequestedDirection(Direction::LEFT);
            break;
        case EntityCommand::TURN_RIGHT:
            entity.setRequestedDirection(Direction::RIGHT);
            break;
        case EntityCommand::TURN_UP:
            entity.setRequestedDirection(Direction::UP);
            break;
        case EntityCommand::TURN_DOWN:
            entity.setRequestedDirection(Direction::DOWN);
            break;
        default:
            break;
        }
    }

    void PlayerController::onCollision(PlayerModel& entity, const SizedWorldObject& other, World& world)
    {
        switch (other.getCollisionType())
        {
        case (COIN):
            {
                entity.updateObservers(PLAYER_COIN_COLLECTED);
                break;
            }
        case(FRUIT):
            {
                entity.updateObservers(PLAYER_FRUIT_COLLECTED);
                world.sendWorldEvent(FRUIT_EATEN_BY_PLAYER);
                break;
            }
        case(GHOST):
            {
                const auto& ghost = dynamic_cast<const GhostModel&>(other);
                if (ghost.getMode() == GhostModel::CHASE)
                {
                    entity.updateObservers(PLAYER_KILLED);
                    world.sendWorldEvent(PLAYER_KILLED_W);
                    entity.setPosition(entity.getSpawnPosition());
                    entity.setDirection(NONE);
                }
                if (ghost.getMode() == GhostModel::FRIGHTENED)
                {
                    entity.updateObservers(PLAYER_GHOST_KILLED);
                }
                break;
            }
        default:
            {
            }
        }
    }
}

// logic
