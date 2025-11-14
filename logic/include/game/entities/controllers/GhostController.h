//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_GHOSTCONTROLLER_H
#define AP_PACMAN_GHOSTCONTROLLER_H
#include "core/entity/MovingEntityController.h"

namespace logic {

    class GhostController : public MovingEntityController<GhostModel> {
    public:
        void update(World &world, GhostModel &entity) override;
    };

} // logic

#endif //AP_PACMAN_GHOSTCONTROLLER_H
