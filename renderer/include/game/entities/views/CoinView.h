//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COINVIEW_H
#define AP_PACMAN_COINVIEW_H
#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/CoinModel.h"

namespace renderer {

    class CoinView : public ModularEntityView, public logic::IObserver<logic::CoinModel> {
    public:
        CoinView();
        void update(logic::CoinModel &subject) override;

        void setSize(const logic::Size &size) override;
    };

} // renderer

#endif //AP_PACMAN_COINVIEW_H
