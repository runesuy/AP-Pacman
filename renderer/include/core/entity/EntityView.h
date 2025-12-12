//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYVIEW_H
#define AP_PACMAN_ENTITYVIEW_H
#include "core/entity/EntityModel.h"
#include "core/world/IWorldObjectView.h"

namespace renderer {
    /**
     * View class representing the visual aspect of an entity in the game.
     * Inherits from DrawObject to provide drawing capabilities.
     * When inheriting create corresponding EntityModel class to handle logic side.
     *
     * Has a size property to define the dimensions of the entity in the game world.
     */
    class EntityView : public IWorldObjectView {
        logic::Size size = {0, 0};

    public:
        /**
         * Get the size of the entity view.
         * @return
         */
        [[nodiscard]] const logic::Size &getSize() const;

        /**
         * Set the size of the entity view.
         * @param size
         */
        virtual void setSize(const logic::Size &size);
    };
}


#endif //AP_PACMAN_ENTITYVIEW_H
