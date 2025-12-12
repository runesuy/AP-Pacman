//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_POWERUPCONTROLLER_H
#define AP_PACMAN_POWERUPCONTROLLER_H
#include "CollectableController.h"
#include "game/entities/models/FruitModel.h"

namespace logic {
    /**
     * Basic controller for powerup entities.
     * Removes the powerup on collision with the player.
     */
    class PowerupController : public CollectableController<FruitModel> {
    public:
        void update(World &world, FruitModel &entity) override;

        void processCommand(EntityCommand command, FruitModel &entity) override;

        void onCollision(FruitModel &entity, const SizedWorldObject &other, World &world) override;
    };
} // logic

#endif //AP_PACMAN_POWERUPCONTROLLER_H