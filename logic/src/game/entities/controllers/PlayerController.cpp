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
    void PlayerController::processCommand(int command, PlayerModel& entity)
    {
        switch (command)
        {
        case TURN_LEFT:
            entity.setRequestedDirection(LEFT);
            break;
        case TURN_RIGHT:
            entity.setRequestedDirection(RIGHT);
            break;
        case TURN_UP:
            entity.setRequestedDirection(UP);
            break;
        case TURN_DOWN:
            entity.setRequestedDirection(DOWN);
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
                entity.updateObservers(ObserverEvents::PLAYER_COIN_COLLECTED);
                break;
            }
        case(FRUIT):
            {
                entity.updateObservers(ObserverEvents::PLAYER_FRUIT_COLLECTED);
                world.sendWorldEvent(WorldEvents::FRUIT_EATEN_BY_PLAYER);
                break;
            }
        default:
            {
            }
        }
    }

    void PlayerController::handleWorldEvent(WorldObject::WorldEventT event, PlayerModel& entity)
    {
        if (event == WorldEvents::PLAYER_KILLED)
        {
            entity.updateObservers(ObserverEvents::PLAYER_KILLED);
            entity.setPosition(entity.getSpawnPosition());
            entity.setDirection(NONE);
        }

        if (event == WorldEvents::PLAYER_GHOST_KILLED)
        {
            entity.updateObservers(ObserverEvents::PLAYER_GHOST_KILLED);
        }
    }
}

// logic
