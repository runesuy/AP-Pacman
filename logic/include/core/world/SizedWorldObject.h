//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_SIZEDWORLDOBJECT_H
#define AP_PACMAN_SIZEDWORLDOBJECT_H
#include "WorldObject.h"
#include "Size.h"

namespace logic {

    class SizedWorldObject : public WorldObject{
        /**
         * The size of the object.
         */
        Size size={0,0};

    public:
        /**
         * Sets the size of the object.
         * @param size
         */
        virtual void setSize(const Size& size);

        /**
         * @return The size of the object.
         */
        [[nodiscard]] Size getSize() const;

        virtual void onCollision(WorldObject &other) {};
    };

} // logic

#endif //AP_PACMAN_SIZEDWORLDOBJECT_H
