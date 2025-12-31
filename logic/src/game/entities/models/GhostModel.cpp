//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/models/GhostModel.h"
#include "game/entities/controllers/RandomNavGhostController.h"

namespace logic
{
    GhostModel::GhostModel()
    {
        controller = std::make_shared<logic::RandomNavGhostController>();
    }

    void GhostModel::setSize(const Size& size)
    {
        SizedWorldObject::setSize(size);
        updateObservers();
    }

    void GhostModel::setPosition(const Position& position)
    {
        WorldObject::setPosition(position);
        updateObservers();
    }

    void GhostModel::markForRemoval()
    {
        WorldObject::markForRemoval();
        updateObservers();
    }

    float GhostModel::getSpeed() const
    {
        switch (mode)
        {
        default:
            return CHASE_SPEED * difficultyMultiplier;
        case (FRIGHTENED):
            return FRIGHTENED_SPEED * difficultyMultiplier;
        }
    }

    void GhostModel::setDirection(Direction direction)
    {
        MovingEntityModel::setDirection(direction);
        updateObservers();
    }

    float GhostModel::getStartTimer() const
    {
        return startTimer;
    }

    void GhostModel::setStartTimer(float startTimer)
    {
        GhostModel::startTimer = startTimer;
    }

    GhostModel::Mode GhostModel::getMode() const
    {
        return mode;
    }

    void GhostModel::setMode(GhostModel::Mode mode)
    {
        GhostModel::mode = mode;
        updateObservers();
    }

    float GhostModel::getStartDelay() const
    {
        return START_DELAY;
    }

    const Position& GhostModel::getReturnPosition() const
    {
        return returnPosition;
    }

    void GhostModel::setReturnPosition(const Position& returnPosition)
    {
        GhostModel::returnPosition = returnPosition;
    }

    void GhostModel::setStartDelay(const float startDelay)
    {
        START_DELAY = startDelay;
    }

    float GhostModel::getFrightenedTimer() const
    {
        return frightenedTimer;
    }

    void GhostModel::setFrightenedTimer(float frightenedTimer)
    {
        GhostModel::frightenedTimer = frightenedTimer;
        updateObservers();
    }

    float GhostModel::getFrightenedDuration() const
    {
        return FRIGHTENED_DURATION;
    }

    SizedWorldObject::CollisionTypeT GhostModel::getCollisionType() const
    {
        return collisionType;
    }

    GhostModel::GhostModel(float difficultyMultiplier) : difficultyMultiplier(difficultyMultiplier)
    {
        controller = std::make_shared<logic::RandomNavGhostController>();
    }
} // logic
