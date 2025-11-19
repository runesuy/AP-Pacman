//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_PINKGHOSTVIEW_H
#define AP_PACMAN_PINKGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"

namespace renderer {

    class PinkGhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel> {
        bool markedForRemoval{false};
        logic::Direction direction;

        void updateAnimation();

        inline static const std::map<std::string, std::vector<std::string>> animations{
                {"move-right",
                        {"ghost-pink-right_0", "ghost-pink-right_1"},
                },
                {"move-left",
                        {"ghost-pink-left_0",  "ghost-pink-left_1"}
                },
                {"move-up",
                        {"ghost-pink-up_0",    "ghost-pink-up_1"}
                },
                {"move-down",
                        {"ghost-pink-down_0",  "ghost-pink-down_1"}
                }
        };

    public:
        PinkGhostView();

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;

        void setDirection(logic::Direction direction);
    };

} // renderer

#endif //AP_PACMAN_PINKGHOSTVIEW_H
