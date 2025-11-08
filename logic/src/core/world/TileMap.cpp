//
// Created by rune-suy on 11/5/25.
//

#include <iostream>
#include "core/world/TileMap.h"
#include "core/world/World.h"

namespace logic {
    const std::vector<std::vector<TileMap::TileType>> &TileMap::getMapData() const {
        return mapData;
    }

    void TileMap::addRow(const std::vector<TileType> &row) {
        if (!mapData.empty() && row.size() != mapData[0].size()) {
            throw std::invalid_argument("Row size does not match existing map data");
        }
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
                    case TileType::WALL: {
                        auto wall = world.getConfig().getEntityFactory()->createWallModel();
                        wall->setPosition({x, y});
                        wall->setSize({tileSize, tileSize});
                        world.addObject(wall);
                        break;
                    }
                    case TileType::PLAYER: {
                        auto player = world.getConfig().getEntityFactory()->createPlayerModel();
                        player->setPosition({x, y});
                        player->setSize({tileSize, tileSize});
                        world.addObject(player);
                        break;
                    }
                }
            }
        }
    }

    TileMap::TileType TileMap::getTileType(const Position& position) const{
        const auto [row, col] = getGridPosition(position);
        return getTileType(row, col);
    }

    std::pair<int, int> TileMap::getGridPosition(const Position &position) const {
        const float tileSize = 2/static_cast<float>(mapData[0].size());
        const float yOffsetForCentering = (2.0f - tileSize * static_cast<float>(mapData.size())) / 2.0f;
        int col = static_cast<int>(((position.getX() + 1.0f) / tileSize)+tileSize/2);
        int row = static_cast<int>((1.0f - position.getY() - yOffsetForCentering) / tileSize+tileSize/2);
        return {row, col};
    }

    TileMap::TileType TileMap::getTileType(int row, int col) const {
        return mapData.at(row).at(col);
    }

    Position TileMap::getTileCenterPosition(int row, int col) const {
        const float tileSize = 2/static_cast<float>(mapData[0].size());
        const float yOffsetForCentering = (2.0f - tileSize * static_cast<float>(mapData.size())) / 2.0f;
        float x = -1.0f + static_cast<float>(col) * tileSize + tileSize / 2;
        float y = 1.0f - static_cast<float>(row) * tileSize - tileSize / 2 - yOffsetForCentering;
        return {x, y};
    }

} // logic