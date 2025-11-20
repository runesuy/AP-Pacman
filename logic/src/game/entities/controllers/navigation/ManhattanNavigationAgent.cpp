//
// Created by runes on 18/11/2025.
//

#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"
#include "core/world/space/Position.h"
#include <algorithm>
#include <map>
#include <limits>
#include "core/utils/Random.h"

namespace logic {
    Direction ManhattanNavigationAgent::getNavigationDirection(const Position &current, const Position &target,
                                                               const World &world) const {
        const auto& tileMap = world.getConfig().getTileMap();
        auto gridPos = tileMap.getGridPosition(current);

        std::map<Direction, std::pair<double, TileMap::TileType>> m;

        double dRight = _calculateManhattanDistance(gridPos.first, gridPos.second+1, world, target);
        auto typeRight = tileMap.getTileType(gridPos.first, gridPos.second+1);
        m[RIGHT] = {dRight, typeRight};
        double dLeft =  _calculateManhattanDistance(gridPos.first, gridPos.second-1, world, target);
        auto typeLeft = tileMap.getTileType(gridPos.first, gridPos.second-1);
        m[LEFT] = {dLeft, typeLeft};
        double dUp =  _calculateManhattanDistance(gridPos.first-1, gridPos.second, world, target);
        auto typeUp = tileMap.getTileType(gridPos.first-1, gridPos.second);
        m[UP] = {dUp, typeUp};
        double dDown =  _calculateManhattanDistance(gridPos.first+1, gridPos.second, world, target);
        auto typeDown = tileMap.getTileType(gridPos.first+1, gridPos.second);
        m[DOWN] = {dDown, typeDown};

        // calculate viable directions
        auto r = m;
        for (const auto& [d , pr] : m) {
            if (pr.second == TileMap::WALL) {
                r.erase(d);
            }
        }
        m = r;

        // calculate options | result : vector with directions with the smallest distance
        std::vector<Direction> options;
        double minimumDistance=std::numeric_limits<double>::infinity();
        for (const auto& [d , pr] : m) {
            if (pr.first < minimumDistance) {
                minimumDistance = pr.first;
                options = {d};
            }
            else if (pr.first == minimumDistance) {
                options.push_back(d);
            }
        }

        // choose random one of options
        if (options.empty()) return NONE;
        int randomInt = Random::getInstance()->getIntInRange(0, options.size()-1);
        return options.at(randomInt);
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