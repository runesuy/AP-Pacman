//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ICONFIG_H
#define AP_PACMAN_ICONFIG_H

#include "core/world/TileMap.h"
#include "core/entity/IEntityFactory.h"

namespace logic {

    class IConfig {
    public:
        virtual ~IConfig() = default;

        /**
         * Get the tile map configuration.
         * This map is loaded in the world on creation.
         * @return
         */
        [[nodiscard]] virtual TileMap getTileMap() const = 0;

        /**
         * Get the entity factory for creating game entities.
         * @return
         */
        [[nodiscard]] virtual std::shared_ptr<logic::IEntityFactory> getEntityFactory() const = 0;
    };

} // logic

#endif //AP_PACMAN_ICONFIG_H
