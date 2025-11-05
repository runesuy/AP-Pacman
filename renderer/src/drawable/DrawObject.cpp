//
// Created by rune-suy on 11/5/25.
//

#include <SFML/Graphics/Drawable.hpp>
#include "drawable/DrawObject.h"
#include "utils/Camera.h"

namespace renderer {
    void DrawObject::draw(sf::RenderWindow &window) {
        for (auto &shape : getSFShapes()) {
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