//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IENTITYFACTORY_H
#define AP_PACMAN_IENTITYFACTORY_H

#include "game/entities/models/WallModel.h"
#include "game/entities/models/PlayerModel.h"

namespace logic {

    /**
     * Factory interface for creating entity models.
     * Provides methods to create different types of entities.
     * @note This is an interface and should be implemented by concrete factory classes.
     * @note This factory must be passed as logic::Config
     * @note On creation of an entity, it should be fully initialized except for position and size.
     * @note Each method should also initialize any necessary components for the entity on the representation side.
     */
    class IEntityFactory {
    public:
        virtual ~IEntityFactory() = default;

        /**
         * Creates and returns a shared pointer to a WallModel instance.
         * @return A shared pointer to the created WallModel.
         */
        virtual std::shared_ptr<WallModel> createWallModel() = 0;

        virtual std::shared_ptr<PlayerModel> createPlayerModel() = 0;

    };
}


#endif //AP_PACMAN_IENTITYFACTORY_H
