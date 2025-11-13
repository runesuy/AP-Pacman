//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IENTITYFACTORY_H
#define AP_PACMAN_IENTITYFACTORY_H

#include "game/entities/models/WallModel.h"
#include "game/entities/models/PlayerModel.h"
#include "game/entities/models/CoinModel.h"
#include "game/entities/models/PowerupModel.h"
#include "game/entities/models/GhostModel.h"
#include "GhostTypes.h"

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

        /**
         * Creates and returns a shared pointer to a PlayerModel instance.
         * @return A shared pointer to the created PlayerModel.
         */
        virtual std::shared_ptr<PlayerModel> createPlayerModel() = 0;

        /**
         * Creates and returns a shared pointer to a CoinModel instance.
         * @return A shared pointer to the created CoinModel.
         */
        virtual std::shared_ptr<CoinModel> createCoinModel() = 0;

        /**
         * Creates and returns a shared pointer to a PowerupModel instance.
         * @return A shared pointer to the created PowerupModel.
         */
        virtual std::shared_ptr<PowerupModel> createPowerupModel() = 0;

        /**
         * Creates and returns a shared pointer to a GhostModel instance of the specified type.
         * @return
         */
        virtual std::shared_ptr<GhostModel> createGhostModel(GhostType type) = 0;
    };
}


#endif //AP_PACMAN_IENTITYFACTORY_H
