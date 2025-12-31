//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_FRUITMODEL_H
#define AP_PACMAN_FRUITMODEL_H


#include "core/entity/EntityModel.h"
#include "game/entities/models/CollisionTypes.h"
#include "core/observer/Observable.h"

namespace logic
{
    class FruitModel : public EntityModel<FruitModel>, public Observable<FruitModel>
    {
        inline static const CollisionType collisionType = FRUIT;

    public:
        FruitModel();

        void setSize(const Size& size) override;

        void setPosition(const Position& position) override;

        void markForRemoval() override;

        [[nodiscard]] CollisionTypeT getCollisionType() const override;
    };
} // logic

#endif //AP_PACMAN_FRUITMODEL_H
