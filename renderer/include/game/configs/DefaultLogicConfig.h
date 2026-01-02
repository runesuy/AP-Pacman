//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DEFAULTLOGICCONFIG_H
#define AP_PACMAN_DEFAULTLOGICCONFIG_H

#include "core/config/ILogicConfig.h"
#include "core/world/TileMap.h"
#include "game/factories/DefaultEntityFactory.h"

namespace renderer
{
    /**
     * Default implementation of the logic configuration interface.
     */
    class DefaultLogicConfig : public logic::ILogicConfig
    {
        logic::TileMap tileMap;
        std::shared_ptr<logic::IEntityFactory> entityFactory = std::make_shared<DefaultEntityFactory>();
        inline static const std::string DEFAULT_MAP_PATH = "resources/maps/map.txt";

    public:
        /**
         * Get the tile map to be used in the game world.
         * @return
         */
        [[nodiscard]] const logic::TileMap& getTileMap() const override;

        void loadTileMap() override;

        /**
         * Get the entity factory for creating game entities.
         * Contains all the code for creating a logic entities and the rendering counterparts.
         * @return
         */
        [[nodiscard]] std::shared_ptr<logic::IEntityFactory> getEntityFactory() const override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTLOGICCONFIG_H
