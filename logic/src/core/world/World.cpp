//
// Created by runes on 3/11/2025.
//

#include <memory>
#include <iostream>
#include "core/world/World.h"
#include "core/world/TileMap.h"
#include "core/world/CollisionHandler.h"

namespace logic {
    void World::update() {
        // look for collisions between objects
        _handleCollisions();

        // Update all objects in the world
        for (const auto& object : objects) {
            object->update(*this);
        }

        _removeMarkedObjects();
    }

    World::World(const IConfig& config) : config(config) {
        config.getTileMap().loadToWorld(*this);
    }

    const IConfig &World::getConfig() const {
        return config;
    }

    void World::addObject(const std::shared_ptr<WorldObject> &object) {
        objects.push_back(object);
    }

    void World::_handleCollisions() {
        CollisionHandler::handleCollisions(objects);
    }

    void World::removeObject(const WorldObject &object) {
        for (auto it = objects.begin(); it != objects.end(); ) {
            if (it->get() == &object) {
                it = objects.erase(it);
            } else {
                ++it;
            }
        }
        updateObservers();
    }

    void World::_removeMarkedObjects() {
        for (auto it = objects.begin(); it != objects.end(); ) {
            if ((*it)->isMarkedForRemoval()) {
                it = objects.erase(it);
            } else {
                ++it;
            }
        }
        updateObservers();
    }
} // logic