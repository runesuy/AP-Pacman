//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYMODEL_H
#define AP_PACMAN_ENTITYMODEL_H
#include "core/world/Position.h"
#include "vector"
#include "core/observer/Observable.h"
#include "memory"
#include "core/world/SizedWorldObject.h"
#include "core/world/Size.h"
#include "core/entity/IEntityController.h"
#include "EntityCommands.h"

namespace logic {
    template<typename EntityModelType>
    class IEntityController;

    /**
     * In world logical representation of an entity.
     * Consists of size attribute in addition to WorldObject attributes.
     */
    template<typename EntityModelType>
class EntityModel : public SizedWorldObject{
    protected:
        std::shared_ptr<IEntityController<EntityModelType>> controller;

    public:
        void setController(const std::shared_ptr<IEntityController<EntityModelType>> &controller){
            this->controller = controller;
        }

        void processCommand(EntityCommand command){
            if(controller){
                try {
                    controller->processCommand(command, static_cast<EntityModelType &>(*this));
                }
                catch (std::bad_cast& e){
                    // Handle the error appropriately, e.g., log it
                    throw std::runtime_error("Failed to cast EntityModel to EntityModelType in processCommand(): " + std::string(e.what()));
                }
            }
        };

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
