//
// Created by rune-suy on 11/8/25.
//

#ifndef AP_PACMAN_COINMODEL_H
#define AP_PACMAN_COINMODEL_H

#include "core/entity/EntityModel.h"

namespace logic {

    class CoinModel : public EntityModel<CoinModel>, public Observable<CoinModel> {
    public:
        CoinModel();

        void setSize(const Size &size) override;

        void setPosition(const Position &position) override;

        void markForRemoval() override;
    };

} // logic

#endif //AP_PACMAN_COINMODEL_H
