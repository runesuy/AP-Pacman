//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_GHOSTCONTROLLER_H
#define AP_PACMAN_GHOSTCONTROLLER_H

#include "MovingEntityController.h"
#include "core/entity/INavigationAgent.h"
#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"

namespace logic {

    class GhostController : public MovingEntityController<GhostModel> {
        const std::unique_ptr<INavigationAgent> returnNavigationAgent = std::make_unique<ManhattanNavigationAgent>();
        const std::unique_ptr<INavigationAgent> frightenedNavigationAgent = std::make_unique<ManhattanNavigationAgent>();
    public:
        void update(World &world, GhostModel &entity) override;

        void handleWorldEvent(WorldObject::WorldEventT event, GhostModel& entity) override;
    };

} // logic

#endif //AP_PACMAN_GHOSTCONTROLLER_H
