//
// Created by rune-suy on 11/14/25.
//

#include "game/entities/controllers/GhostController.h"
#include "game/WorldEvents.h"

namespace logic {
    void GhostController::update(World &world, GhostModel &entity) {
        MovingEntityController::update(world, entity);
        if (entity.getStartTimer() < entity.getStartDelay())entity.setStartTimer(entity.getStartTimer() + Stopwatch::getInstance()->getDeltaTime());
        else if (entity.getMode() == GhostModel::WAITING) {
            entity.setMode(GhostModel::CHASE);
        }
        if (entity.getMode() == GhostModel::WAITING && entity.getDirection() != Direction::NONE) {
            entity.setRequestedDirection(Direction::NONE);
        }
    }

    void GhostController::handleWorldEvent(WorldObject::WorldEventT event, GhostModel& entity) {
        switch (event) {
            default:{}
            case(WorldEvent::FRUIT_EATEN_BY_PLAYER): {
                entity.setMode(GhostModel::FRIGHTENED);
            }
        }
    }
} // logic