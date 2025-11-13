//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_MOVINGENTITYMODEL_H
#define AP_PACMAN_MOVINGENTITYMODEL_H
#include "EntityModel.h"
#include "Directions.h"

namespace logic {

    template<typename EntityModelType>
    class MovingEntityModel : public EntityModel<EntityModelType> {
    private:
        Direction direction=NONE;
        Direction requestedDirection=NONE;
    public:
        /**
         * @return A constant or variable speed of the moving entity.
         */
        virtual float getSpeed()=0;

        void setRequestedDirection(Direction requestedDirection){
            this->requestedDirection = requestedDirection;
        };

        [[nodiscard]] Direction getRequestedDirection() const{
            return requestedDirection;
        };

        [[nodiscard]] Direction getDirection() const{
            return direction;
        };

        virtual void setDirection(Direction direction) {
            MovingEntityModel::direction = direction;
        }
    };

} // logic

#endif //AP_PACMAN_MOVINGENTITYMODEL_H
