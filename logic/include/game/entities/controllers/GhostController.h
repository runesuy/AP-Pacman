//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_GHOSTCONTROLLER_H
#define AP_PACMAN_GHOSTCONTROLLER_H

#include "MovingEntityController.h"
#include "core/entity/INavigationAgent.h"
#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"
#include "navigation/AStarNavigationAgent.h"

namespace logic {
    /**
     * Controller for basic ghost behavior.
     *
     * MODES:
     * - CHASE: Ghosts will navigate towards the player, implementation needs to be provided by subclass.
     * - FRIGHTENED: Ghosts will maximize manhattan distance from the player.
     * - RETURNING_HOME: Ghosts will navigate back to their spawn point using A* pathfinding.
     *
     * Ghost will start in CHASE mode.
     * On POWER_UP event, ghost will switch to FRIGHTENED mode.
     *
     * While in FRIGHTENED mode, a timer is set. After the timer expires, the ghost switches back to CHASE mode.
     * The duration of the timer depends on the difficulty multiplier of the ghost.
     */
    class GhostController : public MovingEntityController<GhostModel> {
        const std::unique_ptr<INavigationAgent> returnNavigationAgent = std::make_unique<AStarNavigationAgent>();
        const std::unique_ptr<INavigationAgent> frightenedNavigationAgent = std::make_unique<
            ManhattanNavigationAgent>();

        bool justChangedToFrightened = false;

    protected:
        static bool isAtIntersectionOrDeadEnd(const World &world, const GhostModel &entity);

    public:
        void update(World &world, GhostModel &entity) override;

        void handleWorldEvent(WorldObject::WorldEventT event, GhostModel &entity) override;

        void onCollision(GhostModel &entity, const SizedWorldObject &other, World &world) override;
    };
} // logic

#endif //AP_PACMAN_GHOSTCONTROLLER_H
