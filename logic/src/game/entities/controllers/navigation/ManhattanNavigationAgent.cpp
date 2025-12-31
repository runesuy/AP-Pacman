//
// Created by runes on 18/11/2025.
//

#include "game/entities/controllers/navigation/ManhattanNavigationAgent.h"
#include "core/world/space/Position.h"
#include <algorithm>
#include <map>
#include <limits>
#include <iostream>
#include "core/utils/Random.h"

namespace logic
{
    Direction ManhattanNavigationAgent::getNavigationDirection(const Position& current, const Position& target,
                                                               const World& world,
                                                               std::set<Direction> excludeIfOtherOptions) const
    {
        auto m = _getDirectionMap(current, target, world);
        _removeNonViableDirections(m);

        // calculate options | result : vector with directions with the smallest distance
        double minimumDistance = std::numeric_limits<double>::infinity();
        // calculate options | result : vector with directions with the least distance
        auto comp = [](double current, double compare) -> bool
        {
            return current < compare;
        };

        // in order for more dynamic movement and to not get stuck in certain corners
        // we will only turn 180 degrees if this is the only option:
        auto mWithoutExclude = m;
        erase_if(mWithoutExclude, [excludeIfOtherOptions](auto d) { return excludeIfOtherOptions.contains(d.first); });

        std::set<Direction> options = _selectBestOptions(mWithoutExclude, minimumDistance, comp);
        if (options.empty())
        {
            options = _selectBestOptions(m, minimumDistance, comp);
        }


        // choose random one of options
        if (options.empty()) return NONE;
        int randomInt = Random::getInstance()->getIntInRange(0, options.size() - 1);
        std::vector<Direction> temp = {options.begin(), options.end()};
        return temp.at(randomInt);
    }

    double ManhattanNavigationAgent::_calculateManhattanDistance(const Position& current, const Position& target)
    {
        return std::abs(current.getX() - target.getX()) + std::abs(current.getY() - target.getY());
    }

    double
    ManhattanNavigationAgent::_calculateManhattanDistance(Position::CoordinateType row, Position::CoordinateType col,
                                                          const World& world,
                                                          const Position& target)
    {
        auto position = world.getConfig().getTileMap().getTileCenterPosition(row, col);
        return _calculateManhattanDistance(position, target);
    }

    std::map<Direction, std::pair<double, TileMap::TileType>>
    ManhattanNavigationAgent::_getDirectionMap(const Position& current, const Position& target, const World& world)
    {
        std::map<Direction, std::pair<double, TileMap::TileType>> m;
        const auto& tileMap = world.getConfig().getTileMap();
        auto gridPos = tileMap.getGridPosition(current);
        double dRight = _calculateManhattanDistance(gridPos.first, gridPos.second + 1, world, target);
        auto typeRight = tileMap.getTileType(gridPos.first, gridPos.second + 1);
        m[RIGHT] = {dRight, typeRight};
        double dLeft = _calculateManhattanDistance(gridPos.first, gridPos.second - 1, world, target);
        auto typeLeft = tileMap.getTileType(gridPos.first, gridPos.second - 1);
        m[LEFT] = {dLeft, typeLeft};
        double dUp = _calculateManhattanDistance(gridPos.first - 1, gridPos.second, world, target);
        auto typeUp = tileMap.getTileType(gridPos.first - 1, gridPos.second);
        m[UP] = {dUp, typeUp};
        double dDown = _calculateManhattanDistance(gridPos.first + 1, gridPos.second, world, target);
        auto typeDown = tileMap.getTileType(gridPos.first + 1, gridPos.second);
        m[DOWN] = {dDown, typeDown};
        return m;
    }

    void ManhattanNavigationAgent::_removeNonViableDirections(ManhattanNavigationAgent::DirectionsMap& m)
    {
        auto r = m;
        for (const auto& [d, pr] : m)
        {
            if (pr.second == TileMap::WALL)
            {
                r.erase(d);
            }
        }
        m = r;
    }

    Direction ManhattanNavigationAgent::getNavigationDirectionAway(const Position& current, const Position& target,
                                                                   const World& world,
                                                                   std::set<Direction> excludeIfOtherOptions) const
    {
        auto m = _getDirectionMap(current, target, world);
        _removeNonViableDirections(m);

        // calculate options | result : vector with directions with the largest distance
        auto comp = [](double current, double compare) -> bool
        {
            return current > compare;
        };

        // in order for more dynamic movement and to not get stuck in certain corners
        // we will only turn 180 degrees if this is the only option:
        auto mWithoutExclude = m;
        erase_if(mWithoutExclude, [excludeIfOtherOptions](auto d) { return excludeIfOtherOptions.contains(d.first); });

        std::set<Direction> options = _selectBestOptions(mWithoutExclude, -1, comp);
        if (options.empty())
        {
            options = _selectBestOptions(m, -1, comp);
        }

        // choose random one of options
        if (options.empty()) return NONE;
        int randomInt = Random::getInstance()->getIntInRange(0, options.size() - 1);
        std::vector<Direction> temp = {options.begin(), options.end()};
        return temp.at(randomInt);
    }

    std::set<Direction>
    ManhattanNavigationAgent::_selectBestOptions(const ManhattanNavigationAgent::DirectionsMap& directionsMap,
                                                 double start,
                                                 const std::function<bool(double current,
                                                                          double compare)>& compare)
    {
        std::set<Direction> options;
        const double eps = 0.01;
        double maximumDistance = start;
        for (const auto& [d, pr] : directionsMap)
        {
            if (std::abs(pr.first - maximumDistance) < eps)
            {
                options.insert(d);
            }
            else if (compare(pr.first, maximumDistance))
            {
                maximumDistance = pr.first;
                options = {d};
            }
        }
        return options;
    }
} // logic
