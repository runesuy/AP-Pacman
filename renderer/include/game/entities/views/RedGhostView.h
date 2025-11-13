//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_REDGHOSTVIEW_H
#define AP_PACMAN_REDGHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"

namespace renderer {

    class RedGhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel>{
        bool markedForRemoval{false};
    public:
        RedGhostView();

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;
    };

} // renderer

#endif //AP_PACMAN_REDGHOSTVIEW_H
