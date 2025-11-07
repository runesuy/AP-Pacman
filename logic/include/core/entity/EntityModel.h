//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYMODEL_H
#define AP_PACMAN_ENTITYMODEL_H
#include "core/world/Position.h"
#include "vector"
#include "core/observer/Observable.h"
#include "memory"
#include "core/world/WorldObject.h"
#include "core/world/Size.h"
#include "core/entity/IEntityController.h"

namespace logic {
    class IEntityController;

    /**
     * In world logical representation of an entity.
     * Consists of size attribute in addition to WorldObject attributes.
     */
class EntityModel : public WorldObject, public std::enable_shared_from_this<EntityModel>{
    protected:
        std::shared_ptr<IEntityController> controller;

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

        void setController(const std::shared_ptr<IEntityController> &controller);

        void update() override;
    };
}


#endif //AP_PACMAN_ENTITYMODEL_H
