//
// Created by rune-suy on 11/13/25.
//

#include "game/entities/views/RedGhostView.h"
#include "core/entity/modular/modules/RectangleModule.h"

namespace renderer {
    void RedGhostView::update(logic::GhostModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

    bool RedGhostView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void RedGhostView::markForRemoval() {
        markedForRemoval = true;
    }

    void RedGhostView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    RedGhostView::RedGhostView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::Red);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }
} // renderer