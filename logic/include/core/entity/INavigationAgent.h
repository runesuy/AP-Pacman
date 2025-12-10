//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_INAVIGATIONAGENT_H
#define AP_PACMAN_INAVIGATIONAGENT_H

#include "core/world/space/Position.h"
#include "core/world/World.h"
#include <set>

namespace logic {

    /**
     * A navigationAgent providing directions based on the current position, targetPosition and world.
     */
    class INavigationAgent {
    public:
        virtual ~INavigationAgent() = default;

        /**
         * Get directions from current to target.
         * @param current The current position from which is navigated.
         * @param target The position current wants to go to.
         * @param world The game world.
         * @param excludeIfOtherOptions Directions only to be used if no other options are available.
         * @return A direction to proceed to in order to get from current to target.
         */
        [[nodiscard]] virtual Direction
        getNavigationDirection(const Position &current, const Position &target, const World &world,
                               std::set<Direction> excludeIfOtherOptions={}) const = 0;

        /**
         * Get directions from current away from target.
         * @param current The current position from which is navigated.
         * @param target The position current wants to get away from.
         * @param world The game world.
         * @param excludeIfOtherOptions Directions only to be used if no other options are available.
         * @return A direction to proceed to in order to get away from target.
         */
        [[nodiscard]] virtual Direction
        getNavigationDirectionAway(const Position &current, const Position &target, const World &world,
                                   std::set<Direction> excludeIfOtherOptions={}) const = 0;
    };

} // logic

#endif //AP_PACMAN_INAVIGATIONAGENT_H
