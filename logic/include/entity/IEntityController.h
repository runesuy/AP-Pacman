//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_IENTITYCONTROLLER_H
#define AP_PACMAN_IENTITYCONTROLLER_H
#include <memory>

namespace logic {
    class EntityModel;

    class IEntityController {
    public:
        virtual void update(std::shared_ptr<EntityModel> entity) = 0;

        virtual void onCollision(std::shared_ptr<EntityModel> thisEntity, std::shared_ptr<EntityModel> otherEntity) = 0;
    };
}


#endif //AP_PACMAN_IENTITYCONTROLLER_H
