//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_WALLMODEL_H
#define AP_PACMAN_WALLMODEL_H

#include "IEntityModel.h"

namespace logic {

    class WallModel : public IEntityModel {
    public:
        WallModel()=default;

        void update() override;
    };

} // logic

#endif //AP_PACMAN_WALLMODEL_H
