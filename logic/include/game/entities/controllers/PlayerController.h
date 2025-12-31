//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERCONTROLLER_H
#define AP_PACMAN_PLAYERCONTROLLER_H

#include "game/entities/models/PlayerModel.h"
#include "core/world/TileMap.h"
#include "MovingEntityController.h"

namespace logic
{
    /**
     * Controller for the player entity.
     * Responds to arrow key commands to move the player in the given direction.
     * Throws various events on the PlayerModel based on collisions.
     */
    class PlayerController : public MovingEntityController<PlayerModel>
    {
    public:
        void processCommand(EntityCommand command, PlayerModel& entity) override;

        void onCollision(PlayerModel& entity, const SizedWorldObject& other, World& world) override;
    };
} // logic

#endif //AP_PACMAN_PLAYERCONTROLLER_H
