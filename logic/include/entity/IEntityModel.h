//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_IENTITYMODEL_H
#define AP_PACMAN_IENTITYMODEL_H
#include "world/Position.h"
#include "vector"
#include "observer/IObservable.h"
#include "memory"

namespace logic {
    /**
     * In world logical representation of an entity.
     */
    class IEntityModel : public IObservable{
        Position position;

    public:
        /**
         * @return The position of the entity inside the world.
         */
        [[nodiscard]] const Position &getPosition() const;

        /**
         * Called on each tick. Handles simulation logic.
         */
        virtual void update()=0;
    };
}


#endif //AP_PACMAN_IENTITYMODEL_H
