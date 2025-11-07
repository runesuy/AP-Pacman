//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/controllers/PlayerController.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"

namespace logic {
    void PlayerController::_turnLeft() {

    }

    void PlayerController::_turnRight() {

    }

    void PlayerController::_turnUp() {

    }

    void PlayerController::_turnDown() {

    }

    void PlayerController::processCommand(EntityCommand command, PlayerModel &entity) {

    }

    void PlayerController::update(World& world, PlayerModel &entity) {
        float delta = Stopwatch::getInstance()->getDeltaTime();



        if (entity.getRequestedDirection() != entity.getDirection()) {
            // For simplicity, we allow instant direction change
            entity.setDirection(entity.getRequestedDirection());
        }

        if (entity.getDirection() == PlayerModel::Direction::LEFT)
            entity.setPosition(entity.getPosition() + Position(-entity.getSpeed(), 0)* delta);
        else if (entity.getDirection() == PlayerModel::Direction::RIGHT)
            entity.setPosition(entity.getPosition() + Position(entity.getSpeed(), 0)*delta);
        else if (entity.getDirection() == PlayerModel::Direction::UP)
            entity.setPosition(entity.getPosition() + Position(0, entity.getSpeed())*delta);
        else if (entity.getDirection() == PlayerModel::Direction::DOWN)
            entity.setPosition(entity.getPosition() + Position(0, -entity.getSpeed())*delta);
    }

} // logic