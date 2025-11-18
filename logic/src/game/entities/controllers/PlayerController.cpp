//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/controllers/PlayerController.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"
#include "core/world/World.h"
#include <typeinfo>
#include "game/entities/models/CollisionTypes.h"

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

    void PlayerController::onCollision(PlayerModel &entity, const SizedWorldObject &other) {

        switch (other.getCollisionType()) {
            case (CollisionType::COIN): {
                entity.updateObservers("COIN_COLLECTED");
            }
            default:{}
        }
    }
}

// logic