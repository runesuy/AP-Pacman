//
// Created by rune-suy on 11/8/25.
//

#include "game/entities/views/CoinView.h"
#include "core/entity/modular/modules/CircleModule.h"

namespace renderer {
    void CoinView::update(logic::CoinModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        if (subject.isMarkedForRemoval()) {
            markForRemoval();
        }
    }

    CoinView::CoinView() {
        auto circleModule = std::make_shared<CircleModule>();
        circleModule->setSize(getSize());
        circleModule->setFillColor(sf::Color::White);
        addModule(circleModule);
        addObserver(circleModule);
    }

    void CoinView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    bool CoinView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void CoinView::onObservableDestroyed(logic::CoinModel &subject) {
        IObserver::onObservableDestroyed(subject);
    }

    void CoinView::markForRemoval() {
        markedForRemoval = true;
    }
} // renderer