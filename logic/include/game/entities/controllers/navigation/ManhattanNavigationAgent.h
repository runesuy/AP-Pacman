//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
#define AP_PACMAN_MANHATTANNAVIGATIONAGENT_H

#include "core/entity/INavigationAgent.h"
#include <map>

namespace logic {

    class ManhattanNavigationAgent : public INavigationAgent {
        using DirectionsMap = std::map<Direction, std::pair<double, TileMap::TileType>>;
        [[nodiscard]] static double _calculateManhattanDistance(const Position &current, const Position &target) ;

        [[nodiscard]] static double
        _calculateManhattanDistance(Position::CoordinateType row, Position::CoordinateType col, const World &world,
                                    const Position &target) ;

        [[nodiscard]] static DirectionsMap
        _getDirectionMap(const Position &current, const Position &target,
                         const World &world);

        static void _removeNonViableDirections(DirectionsMap& m);

    public:
        [[nodiscard]] Direction
        getNavigationDirection(const Position &current, const Position &target, const World &world) const override;

        Direction
        getNavigationDirectionAway(const Position &current, const Position &target, const World &world) const override;
    };

} // logic

#endif //AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
