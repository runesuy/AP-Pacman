//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_POWERUPCONTROLLER_H
#define AP_PACMAN_POWERUPCONTROLLER_H
#include "CollectableController.h"
#include "game/entities/models/PowerupModel.h"

namespace logic {

    class PowerupController : public CollectableController<PowerupModel> {
    public:
        void update(World &world, PowerupModel &entity) override;

        void processCommand(EntityCommand command, PowerupModel &entity) override;

        void onCollision(PowerupModel &entity, WorldObject &other) override;
    };

} // logic

#endif //AP_PACMAN_POWERUPCONTROLLER_H
