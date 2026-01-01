//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_IWORLDOBJECTVIEW_H
#define AP_PACMAN_IWORLDOBJECTVIEW_H
#include "core/drawable/DrawObject.h"

namespace renderer
{
    class IWorldObjectView : public DrawObject
    {
    public:
        /**
         *
         * @return True if the world object view is marked for removal, false otherwise.
         */
        virtual bool isMarkedForRemoval() =0;
    };
} // renderer

#endif //AP_PACMAN_IWORLDOBJECTVIEW_H
