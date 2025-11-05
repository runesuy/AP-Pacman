//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IWORLDOBJECT_H
#define AP_PACMAN_IWORLDOBJECT_H

#include "Position.h"

namespace logic {

    class IWorldObject {
        Position position;
    public:
        /**
         * @return the position of the world object
         */
        [[nodiscard]] virtual const Position & getPosition() const =0;

        /**
         * Set the position of the world object
         * @param position The new position
         */
        virtual void setPosition(const Position& position)=0;

        /**
         * Update the world object.
         * Called on each game update.
         */
        virtual void update()=0;
    };

} // logic

#endif //AP_PACMAN_IWORLDOBJECT_H
