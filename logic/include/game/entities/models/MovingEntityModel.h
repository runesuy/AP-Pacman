//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_MOVINGENTITYMODEL_H
#define AP_PACMAN_MOVINGENTITYMODEL_H

#include "core/entity/EntityModel.h"
#include "core/entity/Directions.h"

namespace logic {

    /**
     * Entity model containing logic for moving in the world.
     * Use together with a MovingEntityController for easy navigation commands to move in te world while not bumping into walls.
     * @tparam EntityModelType
     */
    template<typename EntityModelType>
    class MovingEntityModel : public EntityModel<EntityModelType> {
    private:
        /**
         * The current direction of the entity;
         */
        Direction direction = NONE;

        /**
         * The direction that the entity needs to change to when it is possible.
         */
        Direction requestedDirection = NONE;
    public:
        /**
         * @return A constant or variable speed of the moving entity.
         */
        virtual float getSpeed() = 0;

        /**
         * Request the entity to turn to requestedDirection when possible.
         * Entity will avoid hitting a wall when turning.
         * @param requestedDirection
         */
        void setRequestedDirection(Direction requestedDirection);

        /**
         * @return The direction the entity wants to go to.
         */
        [[nodiscard]] Direction getRequestedDirection() const;

        /**
         * @return The direction the entity is currently facing.
         */
        [[nodiscard]] Direction getDirection() const;

        /**
         * Set the current direction of the entity.
         * @param direction
         */
        virtual void setDirection(Direction direction);
    };


    //-------------------- IMPLEMENTATION -------------------//

    template<typename EntityModelType>
    void MovingEntityModel<EntityModelType>::setDirection(Direction direction) {
        MovingEntityModel::direction = direction;
    }

    template<typename EntityModelType>
    Direction MovingEntityModel<EntityModelType>::getDirection() const {
        return direction;
    };

    template<typename EntityModelType>
    Direction MovingEntityModel<EntityModelType>::getRequestedDirection() const {
        return requestedDirection;
    };

    template<typename EntityModelType>
    void MovingEntityModel<EntityModelType>::setRequestedDirection(Direction requestedDirection) {
        this->requestedDirection = requestedDirection;
    };

} // logic

#endif //AP_PACMAN_MOVINGENTITYMODEL_H
