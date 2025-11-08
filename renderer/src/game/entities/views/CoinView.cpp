//
// Created by rune-suy on 11/8/25.
//

#include "../../../../include/game/entities/views/CoinView.h"
#include "core/entity/modular/modules/RectangleModule.h"

namespace renderer {
    void CoinView::update(logic::CoinModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

    CoinView::CoinView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::Green);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }

    void CoinView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }
} // renderer