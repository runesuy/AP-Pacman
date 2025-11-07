//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERMODEL_H
#define AP_PACMAN_PLAYERMODEL_H

#include "core/entity/EntityModel.h"

namespace logic {

    class PlayerModel : public EntityModel, public Observable<PlayerModel>{

    };

} // logic

#endif //AP_PACMAN_PLAYERMODEL_H
