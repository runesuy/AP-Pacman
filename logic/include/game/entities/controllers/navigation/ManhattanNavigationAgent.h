//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
#define AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
#include "core/entity/INavigationAgent.h"

namespace logic {

    class ManhattanNavigationAgent : public INavigationAgent{
        double _calculateManhattanDistance(const Position &current, const Position &target) const;
        double
        _calculateManhattanDistance(Position::CoordinateType row, Position::CoordinateType col, const World &world,
                                    const Position &target) const;
    public:
        Direction
        getNavigationDirection(const Position &current, const Position &target, const World &world) const override;
    };

} // logic

#endif //AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
