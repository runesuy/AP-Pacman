//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/controllers/PlayerController.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"
#include "core/world/World.h"

namespace logic {
    void PlayerController::processCommand(EntityCommand command, PlayerModel &entity) {
        switch (command) {
            case EntityCommand::TURN_LEFT:
                entity.setRequestedDirection(PlayerModel::Direction::LEFT);
                break;
            case EntityCommand::TURN_RIGHT:
                entity.setRequestedDirection(PlayerModel::Direction::RIGHT);
                break;
            case EntityCommand::TURN_UP:
                entity.setRequestedDirection(PlayerModel::Direction::UP);
                break;
            case EntityCommand::TURN_DOWN:
                entity.setRequestedDirection(PlayerModel::Direction::DOWN);
                break;
            default:
                break;
        }

    }

    void PlayerController::update(World& world, PlayerModel &entity) {
        float delta = Stopwatch::getInstance()->getDeltaTime();

        TileMap::TileType tileInRequested = getTileInDirection(world, entity, entity.getRequestedDirection());

        if (entity.getRequestedDirection() != entity.getDirection() && tileInRequested != TileMap::TileType::WALL) {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            if (isPastCenter) {
                entity.setPosition(tileCenter);
                entity.setDirection(entity.getRequestedDirection());
            }
        }
        if (entity.getDirection()==PlayerModel::NONE) return;

        TileMap::TileType tileInFront = getTileInDirection(world, entity, entity.getDirection());
        auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
        if (tileInFront != TileMap::TileType::WALL || !isPastCenter) {
            if (entity.getDirection() == PlayerModel::Direction::LEFT)
                entity.setPosition(entity.getPosition() + Position(-entity.getSpeed(), 0)* delta);
            else if (entity.getDirection() == PlayerModel::Direction::RIGHT)
                entity.setPosition(entity.getPosition() + Position(entity.getSpeed(), 0)*delta);
            else if (entity.getDirection() == PlayerModel::Direction::UP)
                entity.setPosition(entity.getPosition() + Position(0, entity.getSpeed())*delta);
            else if (entity.getDirection() == PlayerModel::Direction::DOWN)
                entity.setPosition(entity.getPosition() + Position(0, -entity.getSpeed())*delta);
        }
        else {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            if (isPastCenter) {
                entity.setPosition(tileCenter);
            }
        }
    }

}

    logic::TileMap::TileType logic::PlayerController::getTileInDirection(const World &world, const PlayerModel &entity,
                                                           PlayerModel::Direction direction) {
        auto [row, col] = world.getConfig().getTileMap().getGridPosition(entity.getPosition());

        TileMap::TileType tileInFront;
        switch (direction) {
            case PlayerModel::Direction::LEFT:
                tileInFront = world.getConfig().getTileMap().getTileType(row, col - 1);
                break;
            case PlayerModel::Direction::RIGHT:
                tileInFront = world.getConfig().getTileMap().getTileType(row, col + 1);
                break;
            case PlayerModel::Direction::UP:
                tileInFront = world.getConfig().getTileMap().getTileType(row - 1, col);
                break;
            case PlayerModel::Direction::DOWN:
                tileInFront = world.getConfig().getTileMap().getTileType(row + 1, col);
                break;
        }
        return tileInFront;
    }

std::tuple<bool,logic::Position> logic::PlayerController::_isPastOrOnCenter(const logic::World &world, const logic::PlayerModel &entity,
                                                                            logic::PlayerModel::Direction direction) {
    auto [row, col] = world.getConfig().getTileMap().getGridPosition(entity.getPosition());
    Position tileCenter = world.getConfig().getTileMap().getTileCenterPosition(row, col);
    if (entity.getPosition() == tileCenter) {
        return {true, tileCenter};
    }
    switch (direction) {
        case PlayerModel::Direction::LEFT:
            return {entity.getPosition().getX() < tileCenter.getX(), tileCenter};
        case PlayerModel::Direction::RIGHT:
            return {entity.getPosition().getX() > tileCenter.getX(), tileCenter};
        case PlayerModel::Direction::UP:
            return {entity.getPosition().getY() > tileCenter.getY(), tileCenter};
        case PlayerModel::Direction::DOWN:
            return {entity.getPosition().getY() < tileCenter.getY(), tileCenter};
    }
    return {false, Position(0,0)};
}
// logic