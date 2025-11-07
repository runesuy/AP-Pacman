//
// Created by rune-suy on 11/5/25.
//

#include <SFML/Graphics/Drawable.hpp>
#include "core/drawable/DrawObject.h"
#include "core/utils/Camera.h"

namespace renderer {
    void DrawObject::draw(sf::RenderWindow &window) {
        for (auto &shape : getSFShapes(window)) {
            if (shape->getFillColor() == sf::Color::Yellow) {
                int debug = 0;
                sf::RectangleShape debugRect = dynamic_cast<sf::RectangleShape&>(*shape);
                auto size = debugRect.getSize();
            }
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            window.draw(*shape);
        }
        for (auto &shape : getSFSprites()) {
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            window.draw(*shape);
        }
        for (auto &shape : getSFTexts()) {
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            window.draw(*shape);
        }
    }

    const logic::Position& DrawObject::getPosition() const {
        return position;
    }

    void DrawObject::setPosition(const logic::Position &position) {
        this->position = position;
    }
} // renderer