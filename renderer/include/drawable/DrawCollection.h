//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DRAWCOLLECTION_H
#define AP_PACMAN_DRAWCOLLECTION_H
#include <vector>
#include <memory>
#include "IDrawable.h"

namespace renderer {

    class DrawCollection {
        std::vector<std::shared_ptr<IDrawable>> drawables;

    public:
        DrawCollection() = default;
        void addDrawable(const std::shared_ptr<IDrawable>& drawable);

        const std::vector<std::shared_ptr<IDrawable>>& getDrawables() const;

        void draw(sf::RenderWindow& window);
    };

} // renderer

#endif //AP_PACMAN_DRAWCOLLECTION_H
