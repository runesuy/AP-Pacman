//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERMODEL_H
#define AP_PACMAN_PLAYERMODEL_H

#include "core/entity/MovingEntityModel.h"

namespace logic {

    class PlayerModel : public MovingEntityModel<PlayerModel>, public Observable<PlayerModel>{
    public:
    private:
        const float SPEED = 0.3f;
    public:
        PlayerModel();

        void setPosition(const Position &position) override;

        void setSize(const Size &size) override;

        float getSpeed() override;
    };

} // logic

#endif //AP_PACMAN_PLAYERMODEL_H
