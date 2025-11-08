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
            EMPTY = 0,
            WALL = 1,
            COIN = 2,
            POWER_UP = 3,
            SPAWN = 4,
            GHOST = 5,
            PLAYER = 6
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
        [[nodiscard]] const std::vector<std::vector<TileType>> &getMapData() const;

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

        [[nodiscard]] TileType getTileType(int row, int col) const;

        Position getTileCenterPosition(int row, int col) const;
    };

} // logic

#endif //AP_PACMAN_TILEMAP_H
