//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERCONTROLLER_H
#define AP_PACMAN_PLAYERCONTROLLER_H

#include "core/entity/IEntityController.h"
#include "game/entities/models/PlayerModel.h"

namespace logic {

    class PlayerController : public IEntityController<PlayerModel> {
    public:
        void update(World& world, PlayerModel& entity) override;

        void processCommand(EntityCommand command, PlayerModel &entity) override;

    private:
        void _turnLeft();

        void _turnRight();

        void _turnUp();

        void _turnDown();
    };

} // logic

#endif //AP_PACMAN_PLAYERCONTROLLER_H
