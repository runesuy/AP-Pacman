//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_MOVINGENTITYCONTROLLER_H
#define AP_PACMAN_MOVINGENTITYCONTROLLER_H

#include <iostream>
#include "core/entity/IEntityController.h"
#include "core/utils/Stopwatch.h"
#include "core/world/TileMap.h"
#include "core/world/World.h"

namespace logic
{
    /**
     * Entity controller providing movement logic for entities that can move in the world.
     * @tparam EntityModelType
     */
    template <typename EntityModelType>
    class MovingEntityController : public IEntityController<EntityModelType>
    {
    protected:
        /**
         * Check if the player has passed the center of the current tile in the given direction.
         * @param world
         * @param entity
         * @param direction
         * @return True and the center position if past center, false otherwise.
         */
        static std::tuple<bool, Position> _isPastOrOnCenter(const World& world, const EntityModelType& entity,
                                                            Direction direction);

        static std::tuple<bool, Position> _isPastCenter(const World& world, const EntityModelType& entity,
                                                        Direction direction);

        static double _getTileScaledSpeed(World& world, const EntityModelType& entity);

    public:
        void update(World& world, EntityModelType& entity) override;

        virtual void onWallCollision(World& world, EntityModelType& entity)
        {
        };
    };

    template <typename EntityModelType>
    double MovingEntityController<EntityModelType>::_getTileScaledSpeed(World& world, const EntityModelType& entity)
    {
        double tileSize = world.getConfig().getTileMap().getTileSize();
        return entity.getSpeed() * tileSize;
    }

    template <typename EntityModelType>
    std::tuple<bool, Position>
    MovingEntityController<EntityModelType>::_isPastOrOnCenter(const World& world, const EntityModelType& entity,
                                                               Direction direction)
    {
        const float epsilon = 0.0001f;
        const auto [isPastCenter, tileCenter] = _isPastCenter(world, entity, direction);
        bool isOnCenter = std::abs(tileCenter.getX() - entity.getPosition().getX()) < epsilon && std::abs(
            tileCenter.getY() - entity.getPosition().getY()) < epsilon;
        return {isPastCenter || isOnCenter, tileCenter};
    }

    template <typename EntityModelType>
    void MovingEntityController<EntityModelType>::update(World& world, EntityModelType& entity)
    {
        float delta = Stopwatch::getInstance()->getDeltaTime();

        TileMap::TileType tileInRequested = world.getConfig().getTileMap().getTileInDirection(
            world, entity.getPosition(), entity.getRequestedDirection());

        if (entity.getRequestedDirection() != entity.getDirection() && tileInRequested != TileMap::TileType::WALL)
        {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            if (isPastCenter)
            {
                entity.setPosition(tileCenter);
                entity.setDirection(entity.getRequestedDirection());
            }
        }
        if (entity.getDirection() == NONE) return;

        TileMap::TileType tileInFront = world.getConfig().getTileMap().getTileInDirection(
            world, entity.getPosition(), entity.getDirection());
        auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());

        if (tileInFront != TileMap::TileType::WALL || !isPastCenter)
        {
            double scaledSpeed = _getTileScaledSpeed(world, entity);
            if (entity.getDirection() == LEFT)
                entity.setPosition(entity.getPosition() + Position(-scaledSpeed, 0) * delta);
            else if (entity.getDirection() == RIGHT)
                entity.setPosition(entity.getPosition() + Position(scaledSpeed, 0) * delta);
            else if (entity.getDirection() == UP)
                entity.setPosition(entity.getPosition() + Position(0, scaledSpeed) * delta);
            else if (entity.getDirection() == DOWN)
                entity.setPosition(entity.getPosition() + Position(0, -scaledSpeed) * delta);
        }
        else
        {
            auto [isPastCenter, tileCenter] = _isPastOrOnCenter(world, entity, entity.getDirection());
            if (isPastCenter)
            {
                entity.setPosition(tileCenter);
                onWallCollision(world, entity);
            }
        }
    }

    template <typename EntityModelType>
    std::tuple<bool, Position>
    MovingEntityController<EntityModelType>::_isPastCenter(const World& world, const EntityModelType& entity,
                                                           Direction direction)
    {
        auto [row, col] = world.getConfig().getTileMap().getGridPosition(entity.getPosition());
        Position tileCenter = world.getConfig().getTileMap().getTileCenterPosition(row, col);
        switch (direction)
        {
        case Direction::LEFT:
            return {entity.getPosition().getX() < tileCenter.getX(), tileCenter};
        case Direction::RIGHT:
            return {entity.getPosition().getX() > tileCenter.getX(), tileCenter};
        case Direction::UP:
            return {entity.getPosition().getY() > tileCenter.getY(), tileCenter};
        case Direction::DOWN:
            return {entity.getPosition().getY() < tileCenter.getY(), tileCenter};
        default: return {false, tileCenter};
        }
    }
};
#endif //AP_PACMAN_MOVINGENTITYCONTROLLER_H
