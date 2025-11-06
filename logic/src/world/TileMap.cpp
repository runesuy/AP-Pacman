//
// Created by rune-suy on 11/5/25.
//

#include <iostream>
#include "world/TileMap.h"
#include "world/World.h"

namespace logic {
    const std::vector<std::vector<TileMap::TileType>> &TileMap::getMapData() const {
        return mapData;
    }

    void TileMap::addRow(const std::vector<TileType> &row) {
        mapData.push_back(row);
    }

    void TileMap::loadToWorld(World &world) {
        const float tileSize = 2/static_cast<float>(mapData[0].size());
        const float yOffsetForCentering = (2.0f - tileSize * static_cast<float>(mapData.size())) / 2.0f;
        for (int row=0; row<mapData.size(); row++) {
            for (int col=0; col<mapData[row].size(); col++) {
                TileType tileType = mapData[row][col];
                float x = -1.0f + static_cast<float>(col) * tileSize + tileSize / 2;
                float y = 1.0f - static_cast<float>(row) * tileSize - tileSize / 2 - yOffsetForCentering;
                switch (tileType) {
                    case TileType::WALL:
                        auto wall = world.getConfig().getEntityFactory()->createWallModel();
                        wall->setPosition({x, y});
                        wall->setSize({tileSize, tileSize});
                        world.addObject(wall);
                        break;
                }
            }
        }
    }

} // logic