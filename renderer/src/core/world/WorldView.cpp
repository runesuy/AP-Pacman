//
// Created by rune-suy on 11/9/25.
//

#include "core/world/WorldView.h"
#include "game/Game.h"

namespace renderer {
    void WorldView::update(logic::World &subject) {
        _cleanUpViews();
        if (!subject.getScore().hasObserver(scoreView)) {
           subject.getScore().addObserver(scoreView);
        }
        if (!subject.getScore().getLifeCounter().hasObserver(livesView)) {
            subject.getScore().getLifeCounter().addObserver(livesView);
        }
    }

    void WorldView::_cleanUpViews() {
        for (auto it = objectViews.begin(); it != objectViews.end(); ) {
            if ((*it)->isMarkedForRemoval()) {
                it = objectViews.erase(it);
            } else {
                ++it;
            }
        }
    }

    void WorldView::draw(sf::RenderWindow &window) {
        for( const auto& view : objectViews) {
            view->draw(window);
        }
        scoreView->draw(window);
        livesView->draw(window);
        livesView->setHorizontalOrigin(Label::RIGHT);
        scoreView->setHorizontalOrigin(Label::LEFT);
        const logic::TileMap &tileMap = Game::getInstance()->getAppConfig().getLogicConfig().getTileMap();
        scoreView->setPosition(tileMap.getTileCenterPosition(tileMap.getRowCount(), 0));
        livesView->setPosition(tileMap.getTileCenterPosition(tileMap.getRowCount(), tileMap.getColumnCount()-1));
    }

    void WorldView::addObjectView(const std::shared_ptr<IWorldObjectView> &objectView) {
        objectViews.push_back(objectView);
    }

} // renderer