//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_TILEMAP_H
#define AP_PACMAN_TILEMAP_H

#include "core/observer/Observable.h"
#include "core/world/objects/WorldObject.h"
#include "core/world/space/Size.h"

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
            POWER_UP,
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
         * Afterwards the entity is added to the world.
         * @param world
         */
        void loadToWorld(World &world) const;

        /**
         * Add a row to the tile map.
         * @param row A vector representing a row of tile types.
         * @throws std::invalid_argument if the row size does not match existing rows.
         */
        void addRow(const std::vector<TileType> &row);

        /**
         * @param position World position.
         * @return The original tile at the given position in the world.
         */
        [[nodiscard]] TileType getTileType(const Position &position) const;

        /**
         * @param position
         * @return (row, col) of the position on the map
         */
        [[nodiscard]] std::pair<int, int> getGridPosition(const Position &position) const;

        /**
         *
         * @param row The map row of the requested tile.
         * @param col The map column of the requested tile.
         * @return The original tile at the given position in the world.
         */
        [[nodiscard]] TileType getTileType(unsigned int row, unsigned int col) const;

        /**
         * @param row The map row of the requested tile.
         * @param col The map column of the requested tile.
         * @return The center position of the requested tile.
         */
        [[nodiscard]] Position getTileCenterPosition(unsigned int row, unsigned int col) const;

        /**
         * @return  The size of the grid tiles in the world.
         */
        [[nodiscard]] Size::CoordinateType getTileSize() const;

        /**
         * @return The amount the map is shifted down in order to center it in the middle of the screen.
         */
        [[nodiscard]] Size::CoordinateType getYOffsetForCentering() const;

        /**
         * @return The amount of rows of the map.
         */
        [[nodiscard]] unsigned int getRowCount() const;

        /**
         * @return The amount of columns of the map.
         */
        [[nodiscard]] unsigned int getColumnCount() const;
    };

} // logic

#endif //AP_PACMAN_TILEMAP_H
