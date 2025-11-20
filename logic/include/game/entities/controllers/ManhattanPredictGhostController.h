//
// Created by runes on 20/11/2025.
//

#ifndef AP_PACMAN_MANHATTENPREDICTGHOSTCONTROLLER_H
#define AP_PACMAN_MANHATTENPREDICTGHOSTCONTROLLER_H

#include "GhostController.h"
#include "core/entity/INavigationAgent.h"
#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"

namespace logic {

    /**
     * GhostController that tries to cut of pacman.
     */
    class ManhattanPredictGhostController : public GhostController {
        const std::unique_ptr<INavigationAgent> navigationAgent = std::make_unique<ManhattanNavigationAgent>();

        /**
         * Calculate the position of the entity as if it had taken one step in its current direction.
         * If direction is NONE return entity position unchanged.
         * @tparam Derived
         * @param entity
         * @param stepSize
         * @return Position
         */
        template<class Derived>
        Position _calculatePositionInFrontOneStep(const MovingEntityModel<Derived> &entity, double stepSize);

    public:
        void update(World &world, GhostModel &entity) override;

        void processCommand(EntityCommand command, GhostModel &entity) override;

        void onCollision(GhostModel &entity, const SizedWorldObject &other) override;

    };

    template<class Derived>
    Position ManhattanPredictGhostController::_calculatePositionInFrontOneStep(const MovingEntityModel<Derived> &entity,
                                                                               double stepSize) {
        Position position = entity.getPosition();
        const Direction direction = entity.getDirection();

        switch (direction) {
            case NONE:
                return position;
            case RIGHT:
                position.setX(position.getX() + stepSize);
                break;
            case LEFT:
                position.setX(position.getX() - stepSize);
                break;
            case UP:
                position.setY(position.getY() + stepSize);
                break;
            case DOWN:
                position.setY(position.getY() - stepSize);
                break;
        }
        return position;
    }

} // logic

#endif //AP_PACMAN_MANHATTENPREDICTGHOSTCONTROLLER_H
