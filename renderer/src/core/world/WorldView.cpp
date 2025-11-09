//
// Created by rune-suy on 11/9/25.
//

#include "core/world/WorldView.h"

namespace renderer {
    void WorldView::update(logic::World &subject) {
        _cleanUpViews();
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
    }

    void WorldView::addObjectView(const std::shared_ptr<WorldObjectView> &objectView) {
        objectViews.push_back(objectView);
    }

} // renderer