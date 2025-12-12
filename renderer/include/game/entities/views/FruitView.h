//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_FRUITVIEW_H
#define AP_PACMAN_FRUITVIEW_H

#include "core/observer/IObserver.h"
#include "game/entities/models/FruitModel.h"
#include "core/entity/modular/ModularEntityView.h"

namespace renderer {
    class FruitView : public ModularEntityView, public logic::IObserver<logic::FruitModel> {
        bool markedForRemoval{false};

    public:
        FruitView();

        bool isMarkedForRemoval() override;

        void setSize(const logic::Size &size) override;

        void update(logic::FruitModel &subject) override;

        void markForRemoval();
    };
} // renderer

#endif //AP_PACMAN_FRUITVIEW_H