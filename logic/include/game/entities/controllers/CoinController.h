//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_COINCONTROLLER_H
#define AP_PACMAN_COINCONTROLLER_H

#include "game/entities/models/CoinModel.h"
#include "CollectableController.h"

namespace logic {

    class CoinController : public CollectableController<CoinModel> {
    public:
        void update(World &world, CoinModel &entity) override;

        void processCommand(EntityCommand command, CoinModel &entity) override;

        void onCollision(CoinModel &entity, const SizedWorldObject &other, World &world) override;
    };

} // logic

#endif //AP_PACMAN_COINCONTROLLER_H
