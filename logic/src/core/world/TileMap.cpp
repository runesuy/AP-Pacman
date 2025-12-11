//
// Created by rune-suy on 11/5/25.
//

#include <iostream>
#include "core/world/TileMap.h"
#include "core/world/World.h"

namespace logic {
    const auto &TileMap::getMapData() const {
        return mapData;
    }

    void TileMap::addRow(const std::vector<TileType> &row) {
        if (!mapData.empty() && row.size() != mapData[0].size()) {
            throw std::invalid_argument("Row size does not match existing map data");
        }
        mapData.push_back(row);
    }

    void TileMap::loadToWorld(World &world) const{
        const auto tileSize = getTileSize();
        const auto yOffsetForCentering = (2.0 - tileSize * mapData.size()) / 2.0;
        for (int row=0; row<mapData.size(); row++) {
            for (int col=0; col<mapData[row].size(); col++) {
                TileType tileType = mapData[row][col];
                auto x = -1.0 + static_cast<float>(col) * tileSize + tileSize / 2;
                auto y = 1.0 - static_cast<float>(row) * tileSize - tileSize / 2 - yOffsetForCentering;
                switch (tileType) {
                    default:{
                        break;
                    }
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
                    case TileType::COIN: {
                        auto coin = world.getConfig().getEntityFactory()->createCoinModel();
                        coin->setPosition({x, y});
                        coin->setSize({tileSize * 0.2f, tileSize * 0.2f});
                        world.addObject(coin);
                        break;
                    }
                    case TileType::POWER_UP: {
                        auto powerup = world.getConfig().getEntityFactory()->createPowerupModel();
                        powerup->setPosition({x, y});
                        powerup->setSize({tileSize*0.9, tileSize*0.9});
                        world.addObject(powerup);
                        break;
                    }
                    case TileType::GHOST_RED: {
                        auto ghost = world.getConfig().getEntityFactory()->createGhostModel(GhostType::RED, 1);
                        ghost->setPosition({x, y});
                        ghost->setReturnPosition({x,y});
                        ghost->setSize({tileSize, tileSize});
                        world.addObject(ghost);
                        break;
                    }
                    case TileType::GHOST_PINK: {
                        auto ghost = world.getConfig().getEntityFactory()->createGhostModel(GhostType::PINK, 1);
                        ghost->setPosition({x, y});
                        ghost->setReturnPosition({x,y});
                        ghost->setSize({tileSize, tileSize});
                        world.addObject(ghost);
                        break;
                    }
                    case TileType::GHOST_ORANGE: {
                        auto ghost = world.getConfig().getEntityFactory()->createGhostModel(GhostType::ORANGE, 1);
                        ghost->setPosition({x, y});
                        ghost->setReturnPosition({x,y});
                        ghost->setSize({tileSize, tileSize});
                        world.addObject(ghost);
                        break;
                    }
                    case TileType::GHOST_BLUE: {
                        auto ghost = world.getConfig().getEntityFactory()->createGhostModel(GhostType::BLUE, 1);
                        ghost->setPosition({x, y});
                        ghost->setReturnPosition({x,y});
                        ghost->setSize({tileSize, tileSize});
                        world.addObject(ghost);
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

    TileMap::TileType TileMap::getTileType(unsigned int row, unsigned int col) const {
        return mapData.at(row).at(col);
    }

    Position TileMap::getTileCenterPosition(unsigned int row, unsigned int col) const {
        const float tileSize = 2/static_cast<float>(mapData[0].size());
        const float yOffsetForCentering = (2.0f - tileSize * static_cast<float>(mapData.size())) / 2.0f;
        float x = -1.0f + static_cast<float>(col) * tileSize + tileSize / 2;
        float y = 1.0f - static_cast<float>(row) * tileSize - tileSize / 2 - yOffsetForCentering;
        return {x, y};
    }

    Size::CoordinateType TileMap::getTileSize() const {
        return 2/static_cast<float>(mapData[0].size());
    }

    Size::CoordinateType TileMap::getYOffsetForCentering() const {
        const float tileSize = getTileSize();
        return (2.0f - tileSize * static_cast<float>(mapData.size())) / 2.0f;
    }

    unsigned int TileMap::getRowCount() const {
        return mapData.size();
    }

    unsigned int TileMap::getColumnCount() const {
        return mapData.empty() ? 0 : mapData[0].size();
    }

    std::vector<logic::Direction>
    TileMap::getViableDirections(const logic::World &world, const Position &position) const {
        std::vector<Direction> viableDirections;
        for (Direction dir : {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT}) {
            TileType tileInDirection = getTileInDirection(world, position, dir);
            if (tileInDirection != TileMap::TileType::WALL) {
                viableDirections.push_back(dir);
            }
        }
        return viableDirections;
    }

    TileMap::TileType TileMap::getTileInDirection(const World &world, const Position &position,
                                                                Direction direction) const {
        auto [row, col] = getGridPosition(position);

        TileType tileInFront=EMPTY;
        switch (direction) {
            case LEFT:
                tileInFront = getTileType(row, col - 1);
                break;
            case RIGHT:
                tileInFront = getTileType(row, col + 1);
                break;
            case UP:
                tileInFront = getTileType(row - 1, col);
                break;
            case DOWN:
                tileInFront = getTileType(row + 1, col);
                break;
            case NONE:
                tileInFront = getTileType(row, col);
                break;
        }
        return tileInFront;
    }

} // logic