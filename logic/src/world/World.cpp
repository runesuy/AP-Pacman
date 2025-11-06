//
// Created by runes on 3/11/2025.
//

#include <memory>
#include "world/World.h"

namespace logic {
    void World::update() {

    }

    World::World(std::unique_ptr <IEntityFactory> entityFactory) : entityFactory(std::move(entityFactory)) {

    }
} // logic