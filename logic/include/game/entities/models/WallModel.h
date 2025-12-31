//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_WALLMODEL_H
#define AP_PACMAN_WALLMODEL_H

#include "core/entity/EntityModel.h"
#include "core/observer/Observable.h"

namespace logic
{
    class World;

    /**
     * Entity Model representing a wall in the game world.
     * Observable for integrating with representation layer.
     */
    class WallModel : public EntityModel<WallModel>, public Observable<WallModel>
    {
    public:
        WallModel() = default;

        /**
         * Sets the size of the wall.
         * Calls the observers to update.
         * @param size
         */
        void setSize(const Size& size) override;

        /**
         * Sets the position of the wall.
         * Calls the observers to update.
         * @param size
         */
        void setPosition(const Position& position) override;
    };
} // logic

#endif //AP_PACMAN_WALLMODEL_H
