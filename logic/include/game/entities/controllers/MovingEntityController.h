//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_MOVINGENTITYCONTROLLER_H
#define AP_PACMAN_MOVINGENTITYCONTROLLER_H

#include <iostream>
#include "core/entity/IEntityController.h"
#include "game/entities/models/MovingEntityModel.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"
#include "core/world/World.h"

namespace logic {
    template<typename EntityModelType>
    class MovingEntityController : public IEntityController<EntityModelType> {
    private:

        /**
         * Check if the player has passed the center of the current tile in the given direction.
         * @param world
         * @param entity
         * @param direction
         * @return True and the center position if past center, false otherwise.
         */
        static std::tuple<bool,Position> _isPastOrOnCenter(const logic::World &world, const EntityModelType &entity, Direction direction) ;

    protected:
        static TileMap::TileType getTileInDirection(const World& world, const EntityModelType& entity, Direction direction) ;

    public:
        void update(World &world, EntityModelType &entity) override;

        virtual void onWallCollision(logic::World &world, EntityModelType &entity) {};
        };

    template<typename EntityModelType>
    void MovingEntityController<EntityModelType>::update(World &world, EntityModelType &entity) {
        float delta = Stopwatch::getInstance()->getDeltaTime();

        TileMap::TileType tileInRequested = getTileInDirection(world, entity, entity.getRequestedDirection());

        if (entity.getRequestedDirection() != entity.getDirection() && tileInRequested != TileMap::TileType::WALL) {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            auto ghost = dynamic_cast<GhostModel*>(&entity);
            if (isPastCenter) {
                entity.setPosition(tileCenter);
                entity.setDirection(entity.getRequestedDirection());
            }
        }
        if (entity.getDirection()==Direction::NONE) return;

        TileMap::TileType tileInFront = getTileInDirection(world, entity, entity.getDirection());
        auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
        if (tileInFront != TileMap::TileType::WALL || !isPastCenter) {
            if (entity.getDirection() == Direction::LEFT)
                entity.setPosition(entity.getPosition() + Position(-entity.getSpeed(), 0)* delta);
            else if (entity.getDirection() == Direction::RIGHT)
                entity.setPosition(entity.getPosition() + Position(entity.getSpeed(), 0)*delta);
            else if (entity.getDirection() == Direction::UP)
                entity.setPosition(entity.getPosition() + Position(0, entity.getSpeed())*delta);
            else if (entity.getDirection() == Direction::DOWN)
                entity.setPosition(entity.getPosition() + Position(0, -entity.getSpeed())*delta);
        }
        else {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            if (isPastCenter) {
                entity.setPosition(tileCenter);
                onWallCollision(world, entity);
            }
        }
    }

    template<typename EntityModelType>
    TileMap::TileType
    MovingEntityController<EntityModelType>::getTileInDirection(const World &world, const EntityModelType &entity,
                                                                Direction direction) {
        auto [row, col] = world.getConfig().getTileMap().getGridPosition(entity.getPosition());

        TileMap::TileType tileInFront;
        switch (direction) {
            case Direction::LEFT:
                tileInFront = world.getConfig().getTileMap().getTileType(row, col - 1);
                break;
            case Direction::RIGHT:
                tileInFront = world.getConfig().getTileMap().getTileType(row, col + 1);
                break;
            case Direction::UP:
                tileInFront = world.getConfig().getTileMap().getTileType(row - 1, col);
                break;
            case Direction::DOWN:
                tileInFront = world.getConfig().getTileMap().getTileType(row + 1, col);
                break;
            case Direction::NONE: break;
        }
        return tileInFront;
    }

    template<typename EntityModelType>
    std::tuple<bool, Position>
    MovingEntityController<EntityModelType>::_isPastOrOnCenter(const World &world, const EntityModelType &entity,
                                                               Direction direction) {
        auto [row, col] = world.getConfig().getTileMap().getGridPosition(entity.getPosition());
        Position tileCenter = world.getConfig().getTileMap().getTileCenterPosition(row, col);
        const float epsilon = 0.0001f;
        if (std::abs(tileCenter.getX()-entity.getPosition().getX()) < epsilon && std::abs(tileCenter.getY()-entity.getPosition().getY()) < epsilon) {
            return {true, tileCenter};
        }
        switch (direction) {
            case Direction::LEFT:
                return {entity.getPosition().getX() < tileCenter.getX(), tileCenter};
            case Direction::RIGHT:
                return {entity.getPosition().getX() > tileCenter.getX(), tileCenter};
            case Direction::UP:
                return {entity.getPosition().getY() > tileCenter.getY(), tileCenter};
            case Direction::DOWN:
                return {entity.getPosition().getY() < tileCenter.getY(), tileCenter};
        }
        return {false, Position(0,0)};
    }
};
#endif //AP_PACMAN_MOVINGENTITYCONTROLLER_H
