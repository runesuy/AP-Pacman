//
// Created by runes on 18/11/2025.
//

#ifndef AP_PACMAN_INAVIGATIONAGENT_H
#define AP_PACMAN_INAVIGATIONAGENT_H
#include "core/world/space/Position.h"
#include "core/world/World.h"

namespace logic {

    class INavigationAgent {
    public:
        [[nodiscard]] virtual Direction getNavigationDirection(const Position& current, const Position& target, const World& world) const=0;

        [[nodiscard]] virtual Direction getNavigationDirectionAway(const Position& current, const Position& target, const World& world) const=0;
    };

} // logic

#endif //AP_PACMAN_INAVIGATIONAGENT_H
