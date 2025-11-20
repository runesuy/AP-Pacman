//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COINMODEL_H
#define AP_PACMAN_COINMODEL_H

#include "core/entity/EntityModel.h"
#include "CollisionTypes.h"

namespace logic {

    class CoinModel : public EntityModel<CoinModel>, public Observable<CoinModel> {
        inline static const CollisionType collisionType = COIN;
    public:
        CoinModel();

        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;

        [[nodiscard]] CollisionTypeT getCollisionType() const override;
    };

} // logic

#endif //AP_PACMAN_COINMODEL_H
