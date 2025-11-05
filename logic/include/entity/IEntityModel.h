//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_IENTITYMODEL_H
#define AP_PACMAN_IENTITYMODEL_H
#include "world/Position.h"
#include "vector"
#include "observer/IObservable.h"
#include "memory"
#include "world/IWorldObject.h"

namespace logic {
    /**
     * In world logical representation of an entity.
     */
    class IEntityModel : public IObservable, public IWorldObject{
    public:
    };
}


#endif //AP_PACMAN_IENTITYMODEL_H
