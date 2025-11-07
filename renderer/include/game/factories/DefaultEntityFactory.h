//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DEFAULTENTITYFACTORY_H
#define AP_PACMAN_DEFAULTENTITYFACTORY_H

#include "core/entity/IEntityFactory.h"
#include "game/states/level/LevelState.h"
#include "game/entities/models/PlayerModel.h"

namespace renderer {

    /**
     * Default implementation of the entity factory interface.
     */
    class DefaultEntityFactory : public logic::IEntityFactory {
    public:
        std::shared_ptr<logic::WallModel> createWallModel() override;

        std::shared_ptr<logic::PlayerModel> createPlayerModel() override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTENTITYFACTORY_H
