//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYMODEL_H
#define AP_PACMAN_ENTITYMODEL_H
#include "world/Position.h"
#include "vector"
#include "observer/Observable.h"
#include "memory"
#include "world/WorldObject.h"
#include "world/Size.h"

namespace logic {
    /**
     * In world logical representation of an entity.
     */
    class EntityModel : public WorldObject{
        Size size={0,0};
    public:
        virtual void setSize(const Size& size);
        [[nodiscard]] Size getSize() const;
    };
}


#endif //AP_PACMAN_ENTITYMODEL_H
