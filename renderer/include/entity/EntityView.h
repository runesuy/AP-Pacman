//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYVIEW_H
#define AP_PACMAN_ENTITYVIEW_H
#include "observer/IObserver.h"
#include "entity/IEntityModel.h"

namespace renderer {
    class EntityView : public logic::IObserver<logic::IEntityModel> {

    };
}


#endif //AP_PACMAN_ENTITYVIEW_H
