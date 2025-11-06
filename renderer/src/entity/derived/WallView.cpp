//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "entity/derived/WallView.h"
#include "utils/Camera.h"
#include "entity/modular/modules/RectangleModule.h"
#include "entity/modular/modules/SpriteModule.h"
#include "Game.h"

namespace renderer {
    void WallView::update(std::shared_ptr<logic::WallModel> subject) {
        setPosition(subject->getPosition());
        setSize(subject->getSize());
    }

    WallView::WallView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::White);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }

    void WallView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

} // renderer