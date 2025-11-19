//
// Created by runes on 18/11/2025.
//

#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"
#include "core/world/Position.h"
#include <algorithm>

namespace logic {
    Direction ManhattanNavigationAgent::getNavigationDirection(const Position &current, const Position &target,
                                                               const World &world) const {
        const auto& tileMap = world.getConfig().getTileMap();
        auto gridPos = tileMap.getGridPosition(current);

        double dRight = _calculateManhattanDistance(gridPos.first, gridPos.second+1, world, target);
        auto typeRight = tileMap.getTileType(gridPos.first, gridPos.second+1);
        double dLeft =  _calculateManhattanDistance(gridPos.first, gridPos.second-1, world, target);
        auto typeLeft = tileMap.getTileType(gridPos.first, gridPos.second-1);
        double dUp =  _calculateManhattanDistance(gridPos.first-1, gridPos.second, world, target);
        auto typeUp = tileMap.getTileType(gridPos.first-1, gridPos.second);
        double dDown =  _calculateManhattanDistance(gridPos.first+1, gridPos.second, world, target);
        auto typeDown = tileMap.getTileType(gridPos.first+1, gridPos.second);

        std::vector<double> d = {dDown, dUp, dLeft, dRight};
        while (!d.empty()) {
            double min = 20000;
            for (auto i : d) if (i<min) min=i;
            if (min == dRight && typeRight!=TileMap::WALL) return RIGHT;
            if (min == dLeft && typeLeft != TileMap::WALL) return LEFT;
            if (min == dUp && typeUp != TileMap::WALL) return UP;
            if (min == dDown && typeDown != TileMap::WALL) return DOWN;
            d.erase(std::remove(d.begin(), d.end(), min), d.end());
        }
        return NONE;
    }

    double ManhattanNavigationAgent::_calculateManhattanDistance(const Position &current, const Position &target) const {
        return std::abs(current.getX() - target.getX()) + std::abs(current.getY()-target.getY());
    }

    double
    ManhattanNavigationAgent::_calculateManhattanDistance(Position::CoordinateType row, Position::CoordinateType col,
                                                          const World &world,
                                                          const Position &target) const {
        auto position = world.getConfig().getTileMap().getTileCenterPosition(row, col);
        return _calculateManhattanDistance(position, target);
    }
} // logic