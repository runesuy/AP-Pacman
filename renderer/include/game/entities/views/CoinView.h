//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COINVIEW_H
#define AP_PACMAN_COINVIEW_H
#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/CoinModel.h"

namespace renderer
{
    /**
     * Displays a coin in the game world.
     */
    class CoinView : public ModularEntityView, public logic::IObserver<logic::CoinModel>
    {
        bool markedForRemoval{false};

    public:
        CoinView();

        void update(logic::CoinModel& subject) override;

        void setSize(const logic::Size& size) override;

        bool isMarkedForRemoval() override;

        void onObservableDestroyed(logic::CoinModel& subject) override;

        void markForRemoval();
    };
} // renderer

#endif //AP_PACMAN_COINVIEW_H
