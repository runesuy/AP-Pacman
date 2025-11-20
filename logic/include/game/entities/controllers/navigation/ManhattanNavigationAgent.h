//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
#define AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
#include "core/entity/INavigationAgent.h"

namespace logic {

    class ManhattanNavigationAgent : public INavigationAgent{
        [[nodiscard]] double _calculateManhattanDistance(const Position &current, const Position &target) const;
        [[nodiscard]] double
        _calculateManhattanDistance(Position::CoordinateType row, Position::CoordinateType col, const World &world,
                                    const Position &target) const;
    public:
        [[nodiscard]] Direction
        getNavigationDirection(const Position &current, const Position &target, const World &world) const override;
    };

} // logic

#endif //AP_PACMAN_MANHATTANNAVIGATIONAGENT_H
