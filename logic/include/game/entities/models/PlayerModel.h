//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERMODEL_H
#define AP_PACMAN_PLAYERMODEL_H

#include "core/entity/EntityModel.h"

namespace logic {

    class PlayerModel : public EntityModel, public Observable<PlayerModel>{
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        Direction direction;
    public:
        void setPosition(const Position &position) override;

        void setSize(const Size &size) override;

        Direction getDirection() const;

        void setDirection(Direction direction);
    };

} // logic

#endif //AP_PACMAN_PLAYERMODEL_H
