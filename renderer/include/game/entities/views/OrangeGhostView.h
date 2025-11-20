//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_ORANGEGHOSTVIEW_H
#define AP_PACMAN_ORANGEGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"

namespace renderer {

    class OrangeGhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel> {
        bool markedForRemoval{false};
        logic::Direction direction;

        void updateAnimation();

        inline static const std::map<std::string, std::vector<std::string>> animations{
                {"move-right",
                        {"ghost-orange-right_0", "ghost-orange-right_1"},
                },
                {"move-left",
                        {"ghost-orange-left_0",  "ghost-orange-left_1"}
                },
                {"move-up",
                        {"ghost-orange-up_0",    "ghost-orange-up_1"}
                },
                {"move-down",
                        {"ghost-orange-down_0",  "ghost-orange-down_1"}
                }
        };

    public:
        OrangeGhostView();

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;

        void setDirection(logic::Direction direction);
    };

} // renderer

#endif //AP_PACMAN_ORANGEGHOSTVIEW_H
