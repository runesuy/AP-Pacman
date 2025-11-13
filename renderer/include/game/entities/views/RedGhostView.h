//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_REDGHOSTVIEW_H
#define AP_PACMAN_REDGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"

namespace renderer {

    class RedGhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel> {
        bool markedForRemoval{false};
        logic::Direction direction;

        void updateAnimation();

        inline static const std::map<std::string, std::vector<std::string>> animations{
                {"move-right",
                        {"ghost-red-right_0", "ghost-red-right_1"},
                },
                {"move-left",
                        {"ghost-red-left_0",  "ghost-red-left_1"}
                },
                {"move-up",
                        {"ghost-red-up_0",    "ghost-red-up_1"}
                },
                {"move-down",
                        {"ghost-red-down_0",  "ghost-red-down_1"}
                }
        };

    public:
        RedGhostView();

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;

        void setDirection(logic::Direction direction);
    };

} // renderer

#endif //AP_PACMAN_REDGHOSTVIEW_H
