//
// Created by runes on 3/11/2025.
//

#include <memory>
#include "core/world/World.h"
#include "core/world/TileMap.h"

namespace logic {
    void World::update() {
        for (const auto& object : objects) {
            object->update(*this);
        }
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
} // logic