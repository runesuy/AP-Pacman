//
// Created by rune-suy on 11/6/25.
//

#include "game/factories/DefaultEntityFactory.h"
#include "game/entities/views/WallView.h"
#include "game/entities/models/WallModel.h"
#include "game/Game.h"
#include "game/entities/views/PlayerView.h"
#include "game/entities/views/CoinView.h"

namespace renderer {
    std::shared_ptr<logic::WallModel> DefaultEntityFactory::createWallModel() {
        auto wallView = std::make_shared<WallView>();
        auto wallModel = std::make_shared<logic::WallModel>();
        wallModel->addObserver(wallView);
        Game::getInstance()->getDrawCollection().addDrawable(wallView);
        return wallModel;
    }

    std::shared_ptr<logic::PlayerModel> DefaultEntityFactory::createPlayerModel() {
            auto playerView = std::make_shared<PlayerView>();
            auto playerModel = std::make_shared<logic::PlayerModel>();
            playerModel->addObserver(playerView);
            Game::getInstance()->getDrawCollection().addDrawable(playerView);
            return playerModel;
    }

    std::shared_ptr<logic::CoinModel> DefaultEntityFactory::createCoinModel() {
        auto coinView = std::make_shared<CoinView>();
        auto coinModel = std::make_shared<logic::CoinModel>();
        coinModel->addObserver(coinView);
        Game::getInstance()->getDrawCollection().addDrawable(coinView);
        return coinModel;
    }
} // renderer