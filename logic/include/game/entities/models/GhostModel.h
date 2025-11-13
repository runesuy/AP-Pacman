//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_GHOSTMODEL_H
#define AP_PACMAN_GHOSTMODEL_H

#include "core/entity/MovingEntityModel.h"

namespace logic {

    class GhostModel : public MovingEntityModel<GhostModel>, public Observable<GhostModel>{
        const float SPEED = 0.2f;
    public:
        GhostModel();
        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;

        float getSpeed() override;

        void setDirection(Direction direction) override;
    };

} // logic

#endif //AP_PACMAN_GHOSTMODEL_H
