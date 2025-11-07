//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERCONTROLLER_H
#define AP_PACMAN_PLAYERCONTROLLER_H

#include "core/entity/IEntityController.h"

namespace logic {

    class PlayerController : public IEntityController {
    public:
        void update(std::shared_ptr<EntityModel> entity) override;

        void processCommand(EntityCommand command, EntityModel &entity) override;

    private:
        void _turnLeft();

        void _turnRight();

        void _turnUp();

        void _turnDown();
    };

} // logic

#endif //AP_PACMAN_PLAYERCONTROLLER_H
