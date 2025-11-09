//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_POWERUPMODEL_H
#define AP_PACMAN_POWERUPMODEL_H


#include "core/entity/EntityModel.h"

namespace logic {

    class PowerupModel : public EntityModel<PowerupModel>, public Observable<PowerupModel> {
        PowerupModel() = default;
        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;
    };

} // logic

#endif //AP_PACMAN_POWERUPMODEL_H
