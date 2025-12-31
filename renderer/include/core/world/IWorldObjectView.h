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
        virtual bool isMarkedForRemoval() =0;
    };
} // renderer

#endif //AP_PACMAN_IWORLDOBJECTVIEW_H
