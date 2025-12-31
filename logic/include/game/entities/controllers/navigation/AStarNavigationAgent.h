//
// Created by runes on 9/12/2025.
//

#ifndef AP_PACMAN_ASTARNAVIGATIONAGENT_H
#define AP_PACMAN_ASTARNAVIGATIONAGENT_H
#include "core/entity/INavigationAgent.h"

// A* pathfinding algorithm implementation
// based on: https://www.geeksforgeeks.org/dsa/a-search-algorithm/

namespace logic
{
    /**
     * Computes navigation directions using the A* pathfinding algorithm.
     * @warning Does not support away navigation.
     */
    class AStarNavigationAgent : public INavigationAgent
    {
    public:
        [[nodiscard]] Direction getNavigationDirection(const Position& current, const Position& target,
                                                       const World& world,
                                                       std::set<Direction> excludeIfOtherOptions) const override;

        /**
         * @warning NO SUPPORT FOR AWAY NAVIGATION
         * @param current
         * @param target
         * @param world
         * @param excludeIfOtherOptions
         * @return
         */
        [[nodiscard]] Direction getNavigationDirectionAway(const Position& current, const Position& target,
                                                           const World& world,
                                                           std::set<Direction> excludeIfOtherOptions) const override
        {
            return NONE;
        };
    };
} // logic

#endif //AP_PACMAN_ASTARNAVIGATIONAGENT_H
