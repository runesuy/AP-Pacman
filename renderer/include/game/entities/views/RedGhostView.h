//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_REDGHOSTVIEW_H
#define AP_PACMAN_REDGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "GhostView.h"

namespace renderer
{
    /**
     * Displays the red ghost with its specific animations.
     */
    class RedGhostView : public GhostView
    {
        inline static const std::map<std::string, std::vector<std::string>> animations{
            {
                "move-right",
                {"ghost-red-right_0", "ghost-red-right_1"},
            },
            {
                "move-left",
                {"ghost-red-left_0", "ghost-red-left_1"}
            },
            {
                "move-up",
                {"ghost-red-up_0", "ghost-red-up_1"}
            },
            {
                "move-down",
                {"ghost-red-down_0", "ghost-red-down_1"}
            },
            {
                "move-right-frightened",
                {"ghost-frightened-right_0", "ghost-frightened-right_1"},
            },
            {
                "move-left-frightened",
                {"ghost-frightened-left_0", "ghost-frightened-left_1"}
            },
            {
                "move-up-frightened",
                {"ghost-frightened-up_0", "ghost-frightened-up_1"}
            },
            {
                "move-down-frightened",
                {"ghost-frightened-down_0", "ghost-frightened-down_1"}
            },
            {
                "move-right-frightened-end",
                {
                    "ghost-frightened-right_0", "ghost-frightened-right_0_end", "ghost-frightened-right_1",
                    "ghost-frightened-right_1_end"
                },
            },
            {
                "move-left-frightened-end",
                {
                    "ghost-frightened-left_0", "ghost-frightened-left_0_end", "ghost-frightened-left_1",
                    "ghost-frightened-left_1_end"
                }
            },
            {
                "move-up-frightened-end",
                {
                    "ghost-frightened-up_0", "ghost-frightened-up_0_end", "ghost-frightened-up_1",
                    "ghost-frightened-up_1_end"
                }
            },
            {
                "move-down-frightened-end",
                {
                    "ghost-frightened-down_0", "ghost-frightened-down_0_end", "ghost-frightened-down_1",
                    "ghost-frightened-down_1_end"
                }
            },
            {
                "move-right-returning",
                {"ghost-returning-right"}
            },
            {
                "move-left-returning",
                {"ghost-returning-left"}
            },
            {
                "move-up-returning",
                {"ghost-returning-up"}
            },
            {
                "move-down-returning",
                {"ghost-returning-down"}
            },
        };

    public:
        RedGhostView();
    };
} // renderer

#endif //AP_PACMAN_REDGHOSTVIEW_H
