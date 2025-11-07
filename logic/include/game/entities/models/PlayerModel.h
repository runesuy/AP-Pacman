//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERMODEL_H
#define AP_PACMAN_PLAYERMODEL_H

#include "core/entity/EntityModel.h"

namespace logic {

    class PlayerModel : public EntityModel<PlayerModel>, public Observable<PlayerModel>{
    public:
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
    private:
        const float SPEED = 0.3f;
        Direction direction=RIGHT;
        Direction requestedDirection=DOWN;
    public:
        PlayerModel();

        void setPosition(const Position &position) override;

        void setSize(const Size &size) override;

        [[nodiscard]] Direction getDirection() const;

        void setDirection(Direction direction);

        [[nodiscard]] float getSpeed() const;

        [[nodiscard]] Direction getRequestedDirection() const;

        void setRequestedDirection(Direction requestedDirection);
    };

} // logic

#endif //AP_PACMAN_PLAYERMODEL_H
