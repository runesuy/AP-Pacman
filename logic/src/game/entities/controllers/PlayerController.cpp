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
                // dynamic_casts are used here to access the GhostModel specific methods
                // I could avoid this cast by putting some of this logic in the ghostController itself and send a world event
                // however I think this is more straightforward and easier to follow, since all player logic is neatly in the playercontroller,
                // so a dynamic_cast is acceptable here
                try
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
                }
                catch (const std::bad_cast& e)
                {
                    // this other has a ghost collision type but is not a ghost model?
                    throw std::runtime_error(
                        "Ghost collision with non-ghost model detected in PlayerController onCollision");
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
