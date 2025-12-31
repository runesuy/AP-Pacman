//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYMODEL_H
#define AP_PACMAN_ENTITYMODEL_H

#include "core/world/space/Position.h"
#include "memory"
#include "core/world/objects/SizedWorldObject.h"
#include "core/entity/IEntityController.h"
#include "EntityCommands.h"

namespace logic
{
    template <typename EntityModelType>
    class IEntityController;

    /**
     * In world logical representation of an entity.
     * Consists of size attribute in addition to WorldObject attributes.
     * Modifying happens via a EntityController
     * @tparam Derived
     *
     * @see EntityController<>
     */
    template <typename Derived>
    class EntityModel : public SizedWorldObject
    {
    protected:
        /**
         * The controller connected to the model.
         * The controller handles input, update and collisions,
         * meaning that the controller contains all logic that changes the model data.
         */
        std::shared_ptr<IEntityController<Derived>> controller;

        /**
         * Position on first update.
         */
        bool spawnPositionSet = false;

        /**
         * The initial position of the entity on the first update.
         */
        Position spawnPosition;

    public:
        /**
         * Creates a default EntityModel.
         */
        EntityModel() = default;

        ~EntityModel() override = default;

        /**
         * Sets the controller.
         * Controller is used for changing the model data.
         * @param controller
         */
        void setController(const std::shared_ptr<IEntityController<Derived>>& controller);

        /**
         * Update the model based on command.
         * Calls the controller.
         * @param command
         */
        void processCommand(EntityCommand command);

        /**
         * Update the model based on the world and the tick delta.
         * Calls the controller.
         * @param world
         */
        void update(World& world) final;

        /**
         * Handle collision event with other object.
         * Calls the controller.
         * @param other
         */
        void onCollision(const SizedWorldObject& other, World& world) final;

        /**
         * Handle the worldEvent.
         * Calls the controller.
         * @param t
         */
        void handleWorldEvent(WorldEventT t) final;

        /**
         * @return The position the before the first update.
         */
        [[nodiscard]] const Position& getSpawnPosition() const;
    };

    template <typename Derived>
    void EntityModel<Derived>::handleWorldEvent(WorldObject::WorldEventT t)
    {
        if (controller) controller->handleWorldEvent(t, static_cast<Derived&>(*this));
    }

    template <typename Derived>
    const Position& EntityModel<Derived>::getSpawnPosition() const
    {
        return spawnPosition;
    }


    //----------------- Implementation -------------------//
    template <typename Derived>
    void EntityModel<Derived>::onCollision(const SizedWorldObject& other, World& world)
    {
        if (controller)
        {
            controller->onCollision(static_cast<Derived&>(*this), other, world);
        }
    }

    template <typename Derived>
    void EntityModel<Derived>::update(World& world)
    {
        if (!spawnPositionSet)
        {
            spawnPositionSet = true;
            spawnPosition = getPosition();
        }
        if (controller)
        {
            try
            {
                controller->update(world, static_cast<Derived&>(*this));
            }
            catch (std::bad_cast& e)
            {
                // Handle the error appropriately, e.g., log it
                throw std::runtime_error(
                    "Failed to cast EntityModel to Derived in update(): " + std::string(e.what()));
            }
        }
    }

    template <typename Derived>
    void EntityModel<Derived>::processCommand(EntityCommand command)
    {
        if (controller)
        {
            try
            {
                controller->processCommand(command, static_cast<Derived&>(*this));
            }
            catch (std::bad_cast& e)
            {
                // Handle the error appropriately, e.g., log it
                throw std::runtime_error(
                    "Failed to cast EntityModel to Derived in processCommand(): " + std::string(e.what()));
            }
        }
    }

    template <typename EntityModelType>
    void
    EntityModel<
        EntityModelType>::setController(const std::shared_ptr<IEntityController<EntityModelType>>& controller)
    {
        this->controller = controller;
    }
}


#endif //AP_PACMAN_ENTITYMODEL_H
