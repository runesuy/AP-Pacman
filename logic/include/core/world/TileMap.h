//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_TILEMAP_H
#define AP_PACMAN_TILEMAP_H

#include "core/observer/Observable.h"
#include "WorldObject.h"

namespace logic {
    class World;

    class TileMap {
    public:
        /**
         * All possible tile types in the tile map.
         */
        enum TileType {
            EMPTY,
            WALL,
            COIN,
            POWER_UP ,
            SPAWN,
            GHOST_RED,
            GHOST_PINK,
            GHOST_BLUE,
            GHOST_ORANGE,
            PLAYER,
        };
    private:
        /**
         * The tile map data represented as a 2D vector of TileType.
         */
        std::vector<std::vector<TileType>> mapData;
    public:

        /**
         * @return A row major 2d grid representing the tile map's tile types.
         */
        [[nodiscard]] const auto &getMapData() const;

        /**
         * Load the tile map into the given world.
         * An entity is created for each tile based on its type.
         * @param world
         */
        void loadToWorld(World& world);

        /**
         * Add a row to the tile map.
         * @param row A vector representing a row of tile types.
         * @throws std::invalid_argument if the row size does not match existing rows.
         */
        void addRow(const std::vector<TileType>& row);

        [[nodiscard]] TileType getTileType(const Position& position) const;

        [[nodiscard]] std::pair<int, int> getGridPosition(const Position& position) const;

        [[nodiscard]] TileType getTileType(unsigned int row, unsigned int col) const;

        [[nodiscard]] Position getTileCenterPosition(unsigned int row, unsigned int col) const;

        [[nodiscard]] Size::CoordinateType getTileSize() const;

        [[nodiscard]] Size::CoordinateType getYOffsetForCentering() const;

        [[nodiscard]] unsigned int getRowCount() const;

        [[nodiscard]] unsigned int getColumnCount() const;
    };

} // logic

#endif //AP_PACMAN_TILEMAP_H
