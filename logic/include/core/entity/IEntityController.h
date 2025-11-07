//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_IENTITYCONTROLLER_H
#define AP_PACMAN_IENTITYCONTROLLER_H
#include <memory>
#include "EntityCommands.h"

namespace logic {
    class EntityModel;

    class IEntityController {
    public:
        virtual void update(std::shared_ptr<EntityModel> entity) = 0;

        virtual void processCommand(EntityCommand command, EntityModel& entity) = 0;
    };
}


#endif //AP_PACMAN_IENTITYCONTROLLER_H
