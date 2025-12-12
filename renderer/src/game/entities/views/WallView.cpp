//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "game/entities/views/WallView.h"
#include "core/utils/Camera.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"

namespace renderer {
    void WallView::update(logic::WallModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

    WallView::WallView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::Blue);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }

    void WallView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    bool WallView::isMarkedForRemoval() {
        return false;
    }
} // renderer