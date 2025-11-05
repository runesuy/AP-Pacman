//
// Created by rune-suy on 11/5/25.
//

#include "TileMap.h"

namespace logic {
    const std::vector<std::vector<TileMap::TileType>> &TileMap::getMapData() const {
        return mapData;
    }
} // logic