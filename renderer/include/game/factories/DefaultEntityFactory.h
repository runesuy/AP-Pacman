//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DEFAULTENTITYFACTORY_H
#define AP_PACMAN_DEFAULTENTITYFACTORY_H

#include "core/entity/IEntityFactory.h"
#include "game/states/LevelState.h"
#include "game/entities/models/PlayerModel.h"

namespace renderer {

    /**
     * Default implementation of the entity factory interface.
     */
    class DefaultEntityFactory : public logic::IEntityFactory {
        std::shared_ptr<WorldView> viewTarget;
    public:
        std::shared_ptr<logic::WallModel> createWallModel() override;

        std::shared_ptr<logic::PlayerModel> createPlayerModel() override;

        std::shared_ptr<logic::CoinModel> createCoinModel() override;

        std::shared_ptr<logic::FruitModel> createPowerupModel() override;

        [[nodiscard]] const std::shared_ptr<WorldView> &getViewTarget() const;

        void setViewTarget(const std::shared_ptr<WorldView> &viewTarget);

        std::shared_ptr<logic::GhostModel> createGhostModel(logic::GhostType type, float difficultyMultiplier) override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTENTITYFACTORY_H
