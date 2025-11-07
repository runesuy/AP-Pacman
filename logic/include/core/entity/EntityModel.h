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
    template<typename EntityModelType>
    class IEntityController;

    /**
     * In world logical representation of an entity.
     * Consists of size attribute in addition to WorldObject attributes.
     */
    template<typename EntityModelType>
class EntityModel : public WorldObject{
    protected:
        std::shared_ptr<IEntityController<EntityModelType>> controller;

        /**
         * The size of the entity.
         */
        Size size={0,0};
    public:
        /**
         * Sets the size of the entity.
         * @param size
         */
        virtual void setSize(const Size& size) {
            this->size = size;
        }

        /**
         * @return The size of the entity.
         */
        [[nodiscard]] Size getSize() const {
            return size;
        }

        void setController(const std::shared_ptr<IEntityController<EntityModelType>> &controller){
            this->controller = controller;
        }

        void update(World &world) override {
            if(controller){
                try {
                    controller->update(world, static_cast<EntityModelType &>(*this));
                }
                catch (std::bad_cast& e){
                    // Handle the error appropriately, e.g., log it
                    throw std::runtime_error("Failed to cast EntityModel to EntityModelType in update(): " + std::string(e.what()));
                }
            }

        }
    };
}


#endif //AP_PACMAN_ENTITYMODEL_H
