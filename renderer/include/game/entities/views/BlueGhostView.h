//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_BlUEGHOSTVIEW_H
#define AP_PACMAN_BlUEGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"

namespace renderer {

    class BlueGhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel> {
        bool markedForRemoval{false};
        logic::Direction direction;

        void updateAnimation();

        inline static const std::map<std::string, std::vector<std::string>> animations{
                {"move-right",
                        {"ghost-blue-right_0", "ghost-blue-right_1"},
                },
                {"move-left",
                        {"ghost-blue-left_0",  "ghost-blue-left_1"}
                },
                {"move-up",
                        {"ghost-blue-up_0",    "ghost-blue-up_1"}
                },
                {"move-down",
                        {"ghost-blue-down_0",  "ghost-blue-down_1"}
                }
        };

    public:
        BlueGhostView();

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;

        void setDirection(logic::Direction direction);
    };

} // renderer

#endif //AP_PACMAN_BlUEGHOSTVIEW_H
