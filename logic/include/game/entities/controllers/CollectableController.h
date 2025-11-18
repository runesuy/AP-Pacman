//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_COLLECTABLECONTROLLER_H
#define AP_PACMAN_COLLECTABLECONTROLLER_H

#include "core/entity/IEntityController.h"
#include "game/entities/models/PlayerModel.h"

namespace logic {

    template<typename ModelType>
    class CollectableController : public IEntityController<ModelType> {
    public:
        void onCollision(ModelType &entity, const SizedWorldObject &other) override;
    };

    template<typename ModelType>
    void CollectableController<ModelType>::onCollision(ModelType &entity, const SizedWorldObject &other) {
        // if collision with player
        if (dynamic_cast<const EntityModel<PlayerModel> *>(&other)) {
            entity.markForRemoval();
        }
    }

} // logic

#endif //AP_PACMAN_COLLECTABLECONTROLLER_H
