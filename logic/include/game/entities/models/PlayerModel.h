//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERMODEL_H
#define AP_PACMAN_PLAYERMODEL_H

#include "MovingEntityModel.h"
#include "CollisionTypes.h"
#include "core/observer/Observable.h"

namespace logic {
    class PlayerModel : public MovingEntityModel<PlayerModel>, public Observable<PlayerModel> {
        const float SPEED = 5.0;
        inline static const CollisionType collisionType = PLAYER;

    public:
        PlayerModel();

        void setPosition(const Position &position) override;

        void setSize(const Size &size) override;

        [[nodiscard]] float getSpeed() const override;

        void setDirection(Direction direction) override;

        [[nodiscard]] CollisionTypeT getCollisionType() const override;
    };
} // logic

#endif //AP_PACMAN_PLAYERMODEL_H