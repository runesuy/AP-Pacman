//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_WALLVIEW_H
#define AP_PACMAN_WALLVIEW_H

#include "game/entities/models/WallModel.h"
#include "core/entity/modular/ModularEntityView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "observer/Observable.h"

namespace renderer {

    /**
     * View class representing the visual aspect of a wall entity in the game.
     * Inherits from EntityView and implements the observer pattern to update its state based on the WallModel.
     */
    class WallView : public ModularEntityView, public logic::IObserver<logic::WallModel> {
    public:
        WallView();

        void update(std::shared_ptr<logic::WallModel> subject) override;

        void setSize(const logic::Size &size) override;


    };

} // renderer

#endif //AP_PACMAN_WALLVIEW_H
