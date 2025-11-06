//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_TILEMAP_H
#define AP_PACMAN_TILEMAP_H

#include "observer/Observable.h"
#include "WorldObject.h"

namespace logic {
    class World;

    class TileMap {
    public:
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
        std::vector<std::vector<TileType>> mapData;
    public:
        [[nodiscard]] const std::vector<std::vector<TileType>> &getMapData() const;

        void loadToWorld(World& world);

        void addRow(const std::vector<TileType>& row);
    };

} // logic

#endif //AP_PACMAN_TILEMAP_H
