//
// Created by runes on 3/11/2025.
//

#include <memory>
#include <utility>
#include "core/world/World.h"
#include "core/world/TileMap.h"
#include "core/world/objects/CollisionHandler.h"
#include "game/WorldCommand.h"
#include "game/WorldEvents.h"
#include "game/entities/ObserverEvents.h"

namespace logic
{
    void World::update()
    {
        if (!_initialKeyPressed) return;
        score->onTick();

        // look for collisions between objects
        _handleCollisions();

        if (!_initialKeyPressed) return;
        // Update all objects in the world
        for (const auto& object : objects)
        {
            object->update(*this);
        }

        _removeMarkedObjects();
    }

    World::World(const ILogicConfig& config) : config(config)
    {
        config.getTileMap().loadToWorld(*this);
        addObserver(score);
    }

    const ILogicConfig& World::getConfig() const
    {
        return config;
    }

    void World::addObject(const std::shared_ptr<WorldObject>& object)
    {
        objects.push_back(object);
    }

    void World::_handleCollisions()
    {
        CollisionHandler::handleCollisions(objects, *this);
    }

    void World::removeObject(const WorldObject& object)
    {
        for (auto it = objects.begin(); it != objects.end();)
        {
            if (it->get() == &object)
            {
                it = objects.erase(it);
            }
            else
            {
                ++it;
            }
        }
        updateObservers();
    }

    void World::_removeMarkedObjects()
    {
        for (auto it = objects.begin(); it != objects.end();)
        {
            if ((*it)->isMarkedForRemoval())
            {
                it = objects.erase(it);
            }
            else
            {
                ++it;
            }
        }
        updateObservers();
    }

    const Score& World::getScore() const
    {
        return *score;
    }

    std::shared_ptr<Score>& World::getScore()
    {
        return score;
    }

    void World::sendWorldEvent(WorldObject::WorldEventT event)
    {
        for (const auto& obj : objects)
        {
            obj->handleWorldEvent(event);
        }
        _handleWorldEvent(event);
    }

    bool World::levelComplete() const
    {
        return getNumberOfObjectsOfType<CoinModel>()==0;
    }

    bool World::isGameOver() const
    {
        return score->getLifeCounter().getLivesLeft() == 0;
    }

    World::World(const ILogicConfig& config, std::shared_ptr<Score> score) : config(config)
    {
        this->score = std::move(score);
        config.getTileMap().loadToWorld(*this);
        addObserver(this->score);
    }

    void World::receiveCommand(WorldCommandType command)
    {
        if (command == ON_KEY_PRESS)
        {
            _initialKeyPressed = true;
        }
    }

    void World::_handleWorldEvent(WorldObject::WorldEventT worldEvent)
    {
        switch (worldEvent)
        {
        case WorldEvents::PLAYER_GHOST_KILLED:
            {
                updateObservers(ObserverEvents::PLAYER_GHOST_KILLED);
                break;
            }
        case WorldEvents::FRUIT_EATEN_BY_PLAYER:
            {
                updateObservers(ObserverEvents::PLAYER_FRUIT_COLLECTED);
                break;
            }
        case WorldEvents::COIN_COLLECTED:
            {
                updateObservers(ObserverEvents::PLAYER_COIN_COLLECTED);
                break;
            }

        case WorldEvents::PLAYER_KILLED:
            {
                updateObservers(ObserverEvents::PLAYER_KILLED);
                break;
            }
        default:
            {}
        }
        if (worldEvent == WorldEvents::WorldEvent::PLAYER_KILLED)
        {
            _initialKeyPressed = false;
        }
    }

    std::weak_ptr<PlayerModel> World::getPlayerModel()
    {
        return _playerModel;
    }

    void World::setPlayerModel(const std::weak_ptr<PlayerModel>& playerModel)
    {
        _playerModel = playerModel;
    }
} // logic
