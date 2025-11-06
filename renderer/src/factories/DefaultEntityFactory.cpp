//
// Created by rune-suy on 11/6/25.
//

#include "factories/DefaultEntityFactory.h"
#include "entity/WallView.h"
#include "entity/WallModel.h"
#include "Game.h"

namespace renderer {
    std::shared_ptr<logic::WallModel> DefaultEntityFactory::createWallModel() {
        auto wallView = std::make_shared<WallView>();
        auto wallModel = std::make_shared<logic::WallModel>();
        wallModel->addObserver(wallView);
        Game::getInstance()->getDrawCollection().addDrawable(wallView);
        return wallModel;
    }
} // renderer