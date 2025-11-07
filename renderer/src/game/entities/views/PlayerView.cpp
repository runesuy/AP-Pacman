//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/views/PlayerView.h"
#include "core/entity/modular/modules/RectangleModule.h"

namespace renderer {
    void PlayerView::update(logic::PlayerModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

    PlayerView::PlayerView() {
        auto rectangleModule = std::make_shared<RectangleModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setFillColor(sf::Color::Yellow);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }

    void PlayerView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

} // renderer