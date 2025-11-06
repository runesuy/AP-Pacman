//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_WALLMODEL_H
#define AP_PACMAN_WALLMODEL_H

#include "EntityModel.h"

namespace logic {

    class WallModel : public EntityModel, public Observable<WallModel>{
    public:
        WallModel()=default;

        void update() override;

        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;
    };

} // logic

#endif //AP_PACMAN_WALLMODEL_H
