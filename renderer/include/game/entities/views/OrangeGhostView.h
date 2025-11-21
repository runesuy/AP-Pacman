//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_ORANGEGHOSTVIEW_H
#define AP_PACMAN_ORANGEGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"
#include "game/entities/models/GhostModel.h"
#include "GhostView.h"

namespace renderer {

    class OrangeGhostView : public GhostView {
        inline static const AnimationsMap animations{
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
                },
                {"move-right-frightened",
                            {"ghost-frightened-right_0", "ghost-frightened-right_1"},
                },
                {"move-left-frightened",
                            {"ghost-frightened-left_0",  "ghost-frightened-left_1"}
                },
                {"move-up-frightened",
                            {"ghost-frightened-up_0",    "ghost-frightened-up_1"}
                },
                {"move-down-frightened",
                            {"ghost-frightened-down_0",  "ghost-frightened-down_1"}
                }
        };

    public:
        OrangeGhostView();
    };

} // renderer

#endif //AP_PACMAN_ORANGEGHOSTVIEW_H
