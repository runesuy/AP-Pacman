//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERVIEW_H
#define AP_PACMAN_PLAYERVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/PlayerModel.h"

namespace renderer {

    class PlayerView : public ModularEntityView, public logic::IObserver<logic::PlayerModel>{
    public:
        PlayerView()=default;

        void update(logic::PlayerModel &subject) override;

    };

} // renderer

#endif //AP_PACMAN_PLAYERVIEW_H
