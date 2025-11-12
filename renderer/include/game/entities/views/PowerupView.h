//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_POWERUPVIEW_H
#define AP_PACMAN_POWERUPVIEW_H

#include "core/observer/IObserver.h"
#include "game/entities/models/PowerupModel.h"
#include "core/entity/modular/ModularEntityView.h"

namespace renderer {

    class PowerupView : public ModularEntityView, public logic::IObserver<logic::PowerupModel> {
        bool markedForRemoval{false};
    public:
        PowerupView();

        bool isMarkedForRemoval() override;

        void setSize(const logic::Size &size) override;

        void update(logic::PowerupModel &subject) override;

        void markForRemoval();
    };

} // renderer

#endif //AP_PACMAN_POWERUPVIEW_H
