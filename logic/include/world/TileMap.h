//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_TILEMAP_H
#define AP_PACMAN_TILEMAP_H

#include "observer/IObservable.h"

namespace logic {

    class TileMap {
    public:
        enum TileType {
            EMPTY = 0,
            WALL = 1,
            DOT = 2,
            POWER_UP = 3,
        };
    private:
        std::vector<std::vector<TileType>> mapData;
    public:
        [[nodiscard]] const std::vector<std::vector<TileType>> &getMapData() const;
    };

} // logic

#endif //AP_PACMAN_TILEMAP_H
