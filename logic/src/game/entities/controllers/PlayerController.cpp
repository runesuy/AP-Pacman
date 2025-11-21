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

namespace logic {
    void PlayerController::processCommand(EntityCommand command, PlayerModel &entity) {
        switch (command) {
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

    void PlayerController::onCollision(PlayerModel &entity, const SizedWorldObject &other, World &world) {

        switch (other.getCollisionType()) {
            case (CollisionType::COIN): {
                entity.updateObservers(static_cast<int>(ObserverEvent::PLAYER_COIN_COLLECTED));
                break;
            }
            case(CollisionType::FRUIT): {
                world.sendWorldEvent(WorldEvent::FRUIT_EATEN_BY_PLAYER);
                break;
            }
            case(CollisionType::GHOST): {
                const auto& ghost = dynamic_cast<const GhostModel&>(other);
                if (ghost.getMode() == GhostModel::CHASE) {
                    entity.updateObservers(ObserverEvent::PLAYER_KILLED);
                    world.sendWorldEvent(PLAYER_KILLED_W);
                    entity.setPosition(entity.getSpawnPosition());
                    entity.setDirection(NONE);
                }
                if (ghost.getMode() == GhostModel::FRIGHTENED) {
                    entity.updateObservers(ObserverEvent::PLAYER_GHOST_KILLED);
                }
                break;
            }
            default:{}
        }
    }
}

// logic