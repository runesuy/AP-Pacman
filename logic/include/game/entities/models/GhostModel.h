//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_GHOSTMODEL_H
#define AP_PACMAN_GHOSTMODEL_H

#include "MovingEntityModel.h"
#include "CollisionTypes.h"
#include "core/observer/Observable.h"

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
        const float difficultyMultiplier = 1;
        const float CHASE_SPEED = 3.0f;
        const float FRIGHTENED_SPEED = 1.0f;
        Position returnPosition{0, 0};

        Mode mode = WAITING;
        float startTimer = 0.0f;
        float START_DELAY = 3.0f; // seconds

        float frightenedTimer = 0.0f;
        const float FRIGHTENED_DURATION = 10 / difficultyMultiplier;

        const CollisionType collisionType = GHOST;

    public:
        explicit GhostModel();

        explicit GhostModel(float difficultyMultiplier);

        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;

        [[nodiscard]] float getSpeed() const override;

        void setDirection(Direction direction) override;

        [[nodiscard]] float getStartTimer() const;

        void setStartTimer(float startTimer);

        [[nodiscard]] Mode getMode() const;

        [[nodiscard]] const Position &getReturnPosition() const;

        void setReturnPosition(const Position &returnPosition);

        void setMode(Mode mode);

        [[nodiscard]] float getStartDelay() const;

        void setStartDelay(float startDelay);

        [[nodiscard]] float getFrightenedTimer() const;

        void setFrightenedTimer(float frightenedTimer);

        [[nodiscard]] float getFrightenedDuration() const;

        [[nodiscard]] CollisionTypeT getCollisionType() const override;
    };
} // logic

#endif //AP_PACMAN_GHOSTMODEL_H
