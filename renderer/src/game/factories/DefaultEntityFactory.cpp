//
// Created by rune-suy on 11/6/25.
//

#include "game/factories/DefaultEntityFactory.h"
#include "game/entities/views/WallView.h"
#include "game/entities/models/WallModel.h"
#include "game/Game.h"
#include "game/entities/views/PlayerView.h"
#include "game/entities/views/CoinView.h"
#include "game/entities/views/PowerupView.h"
#include "game/entities/views/RedGhostView.h"
#include "game/entities/controllers/ManhattanFollowGhostController.h"
#include "game/entities/controllers/RandomNavGhostController.h"
#include "game/entities/views/PinkGhostView.h"
#include "game/entities/views/OrangeGhostView.h"
#include "game/entities/controllers/ManhattanPredictGhostController.h"
#include "game/entities/views/BlueGhostView.h"

namespace renderer {
    std::shared_ptr<logic::WallModel> DefaultEntityFactory::createWallModel() {
        auto wallView = std::make_shared<WallView>();
        auto wallModel = std::make_shared<logic::WallModel>();
        wallModel->addObserver(wallView);
        viewTarget->addObjectView(wallView);
        return wallModel;
    }

    std::shared_ptr<logic::PlayerModel> DefaultEntityFactory::createPlayerModel() {
        auto playerView = std::make_shared<PlayerView>();
        auto playerModel = std::make_shared<logic::PlayerModel>();
        playerModel->addObserver(playerView);
        viewTarget->addObjectView(playerView);
        return playerModel;
    }

    std::shared_ptr<logic::CoinModel> DefaultEntityFactory::createCoinModel() {
        auto coinView = std::make_shared<CoinView>();
        auto coinModel = std::make_shared<logic::CoinModel>();
        coinModel->addObserver(coinView);
        viewTarget->addObjectView(coinView);
        return coinModel;
    }

    const std::shared_ptr<WorldView> &DefaultEntityFactory::getViewTarget() const {
        return viewTarget;
    }

    void DefaultEntityFactory::setViewTarget(const std::shared_ptr<WorldView> &viewTarget) {
        DefaultEntityFactory::viewTarget = viewTarget;
    }

    std::shared_ptr<logic::PowerupModel> DefaultEntityFactory::createPowerupModel() {
        auto powerupView = std::make_shared<PowerupView>();
        auto powerupModel = std::make_shared<logic::PowerupModel>();
        powerupModel->addObserver(powerupView);
        viewTarget->addObjectView(powerupView);
        return powerupModel;
    }

    std::shared_ptr<logic::GhostModel> DefaultEntityFactory::createGhostModel(logic::GhostType type) {
        switch (type) {
            case logic::GhostType::RED: {
                auto ghostView = std::make_shared<RedGhostView>();
                auto ghostModel = std::make_shared<logic::GhostModel>();
                ghostModel->addObserver(ghostView);
                ghostModel->setController(std::make_shared<logic::RandomNavGhostController>());
                viewTarget->addObjectView(ghostView);
                return ghostModel;
            }
            case logic::GhostType::PINK: {
                auto ghostView = std::make_shared<PinkGhostView>();
                auto ghostModel = std::make_shared<logic::GhostModel>();
                ghostModel->addObserver(ghostView);
                ghostModel->setController(std::make_shared<logic::ManhattanFollowGhostController>());
                viewTarget->addObjectView(ghostView);
                return ghostModel;
            }
            case logic::GhostType::ORANGE: {
                auto ghostView = std::make_shared<OrangeGhostView>();
                auto ghostModel = std::make_shared<logic::GhostModel>();
                ghostModel->addObserver(ghostView);
                ghostModel->setController(std::make_shared<logic::ManhattanPredictGhostController>());
                viewTarget->addObjectView(ghostView);
                return ghostModel;
            }
            case logic::GhostType::BLUE: {
                auto ghostView = std::make_shared<BlueGhostView>();
                auto ghostModel = std::make_shared<logic::GhostModel>();
                ghostModel->addObserver(ghostView);
                ghostModel->setController(std::make_shared<logic::ManhattanPredictGhostController>());
                viewTarget->addObjectView(ghostView);
                return ghostModel;
            }
        }
        return {};
    }
} // renderer