//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ICONFIG_H
#define AP_PACMAN_ICONFIG_H

#include "core/world/TileMap.h"
#include "core/entity/IEntityFactory.h"

namespace logic
{
    /**
     * Config interface for the logic.
     * Needs to be passed to world.
     *
     * The Config contains info for the game's logic section to improve customizability of the game without extensive redesigning of the original code.
     */
    class ILogicConfig
    {
    public:
        virtual ~ILogicConfig() = default;

        /**
         * Get the tile map configuration.
         * This map is loaded in the world on creation.
         *
         * @return The currently loaded tilemap.
         *
         * @see logic::TileMap
         */
        [[nodiscard]] virtual const TileMap& getTileMap() const = 0;

        /**
         * Choose a new map and load it in the config.
         */
        virtual void loadTileMap() = 0;

        /**
         * Get the entity factory for creating game entities.
         * @return A shared ptr to the factory.
         *
         * The entity factory gives the logic an easy interface for creating the logic entities and executing needed
         * rendering logic while keeping logic and rendering separate.
         *
         * @see logic::IEntityFactory
         */
        [[nodiscard]] virtual std::shared_ptr<IEntityFactory> getEntityFactory() const = 0;
    };
} // logic

#endif //AP_PACMAN_ICONFIG_H
