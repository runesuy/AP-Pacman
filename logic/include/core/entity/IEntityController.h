//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_IENTITYCONTROLLER_H
#define AP_PACMAN_IENTITYCONTROLLER_H
#include <memory>
#include "EntityCommands.h"

namespace logic {
    template<typename EntityModelType>
    class EntityModel;

    template<typename EntityModelType>
    class IEntityController {
    public:
        virtual void update(EntityModelType& entity) = 0;

        virtual void processCommand(EntityCommand command, EntityModelType& entity) = 0;
    };
}


#endif //AP_PACMAN_IENTITYCONTROLLER_H
