//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_GHOSTMODEL_H
#define AP_PACMAN_GHOSTMODEL_H

#include "MovingEntityModel.h"

namespace logic {

    class GhostModel : public MovingEntityModel<GhostModel>, public Observable<GhostModel> {
    public:
        enum Mode {
            CHASE,
            FRIGHTENED,
            RETURNING_HOME,
            WAITING
        };
    private:
        const float SPEED = 0.2f;
        Position returnPosition{0, 0};

        Mode mode = WAITING;
        float startTimer = 0.0f;
        float START_DELAY = 3.0f; // seconds
    public:
        explicit GhostModel();

        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;

        float getSpeed() override;

        void setDirection(Direction direction) override;

        [[nodiscard]] float getStartTimer() const;

        void setStartTimer(float startTimer);

        [[nodiscard]] Mode getMode() const;

        [[nodiscard]] const Position &getReturnPosition() const;

        void setReturnPosition(const Position &returnPosition);

        void setMode(Mode mode);

        float getStartDelay() const;

        void setStartDelay(float startDelay);
    };

} // logic

#endif //AP_PACMAN_GHOSTMODEL_H
