//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_IENTITYCONTROLLER_H
#define AP_PACMAN_IENTITYCONTROLLER_H
#include "EntityCommands.h"
#include "core/world/objects/SizedWorldObject.h"

namespace logic
{
    class World;

    template <typename Derived>
    class EntityModel;

    /**
     * A controller for customizable logic for an entityModel.
     * EntityControllers read and modify the models based on updates, events and commands.
     *
     * The Derived type of the entityModel.
     * @tparam DerivedEntityModel
     *
     * @see EntityModel
     */
    template <typename DerivedEntityModel>
    class IEntityController
    {
    public:
        virtual ~IEntityController() = default;

        /**
         * Update the entity based on world and stopwatch data.
         * @param world
         * @param entity
         */
        virtual void update(World& world, DerivedEntityModel& entity) = 0;

        /**
         * Update the entity based on the command.
         * @param command
         * @param entity
         */
        virtual void processCommand(EntityCommand command, DerivedEntityModel& entity) = 0;

        /**
         * Handle a collision between entity and other.
         * @param entity
         * @param other
         */
        virtual void onCollision(DerivedEntityModel& entity, const SizedWorldObject& other, World& world) = 0;

        virtual void handleWorldEvent(WorldObject::WorldEventT event, DerivedEntityModel& entity)
        {
        };
    };
}


#endif //AP_PACMAN_IENTITYCONTROLLER_H
