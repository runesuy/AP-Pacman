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
     * Consists of size attribute in addition to WorldObject attributes.
     */
    class EntityModel : public WorldObject{
        /**
         * The size of the entity.
         */
        Size size={0,0};
    public:
        /**
         * Sets the size of the entity.
         * @param size
         */
        virtual void setSize(const Size& size);

        /**
         * @return The size of the entity.
         */
        [[nodiscard]] Size getSize() const;
    };
}


#endif //AP_PACMAN_ENTITYMODEL_H
