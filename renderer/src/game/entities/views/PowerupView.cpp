//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/views/PowerupView.h"
#include "core/entity/modular/modules/RectangleModule.h"

namespace renderer {
    void PowerupView::update(logic::FruitModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        if (subject.isMarkedForRemoval()) {
            markForRemoval();
        }
    }

    bool PowerupView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    PowerupView::PowerupView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::Yellow);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }

    void PowerupView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    void PowerupView::markForRemoval() {
        markedForRemoval = true;
    }

} // renderer