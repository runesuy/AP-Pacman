//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_MANHATTANFOLLOWGHOSTCONTROLLER_H
#define AP_PACMAN_MANHATTANFOLLOWGHOSTCONTROLLER_H

#include "GhostController.h"
#include "core/entity/INavigationAgent.h"
#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"

namespace logic
{
    /**
     * Implements CHASE mode for ghosts using Manhattan navigation.
     */
    class ManhattanFollowGhostController : public GhostController
    {
        const std::unique_ptr<INavigationAgent> navigationAgent = std::make_unique<ManhattanNavigationAgent>();

    public:
        void update(World& world, GhostModel& entity) override;

        void processCommand(EntityCommand command, GhostModel& entity) override;

        void onCollision(GhostModel& entity, const SizedWorldObject& other, World& world) override;
    };
} // logic

#endif //AP_PACMAN_MANHATTANFOLLOWGHOSTCONTROLLER_H
