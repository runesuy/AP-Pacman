//
// Created by rune-suy on 11/6/25.
//

#include "drawable/DrawCollection.h"

namespace renderer {
    void DrawCollection::draw(sf::RenderWindow &window) {
        for (const auto& drawable : drawables) {
            drawable->draw(window);
        }
    }

    void DrawCollection::addDrawable(const std::shared_ptr<IDrawable> &drawable) {
        drawables.push_back(drawable);
    }

    const std::vector<std::shared_ptr<IDrawable>> &DrawCollection::getDrawables() const {
        return drawables;
    }
} // renderer