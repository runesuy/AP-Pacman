//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_WORLDOBJECTVIEW_H
#define AP_PACMAN_WORLDOBJECTVIEW_H
#include "core/drawable/DrawObject.h"

namespace renderer {

    class WorldObjectView : public DrawObject {
    public:
        virtual bool isMarkedForRemoval()=0;
    };

} // renderer

#endif //AP_PACMAN_WORLDOBJECTVIEW_H
