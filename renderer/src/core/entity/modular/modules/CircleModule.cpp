//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "core/utils/Camera.h"
#include "core/entity/modular/modules/CircleModule.h"

namespace renderer {
    std::vector<std::unique_ptr<sf::Shape> > CircleModule::getSFShapes(sf::RenderWindow &window) const {
        std::vector<std::unique_ptr<sf::Shape> > shapes;
        auto circle = std::make_unique<sf::CircleShape>();
        sf::Vector2 projectedSize = Camera::project(size, window);
        circle->setRadius(std::min(projectedSize.x, projectedSize.y) / 2);
        circle->setPosition({0, 0});
        circle->setFillColor(fillColor);
        circle->setOrigin(circle->getRadius(), circle->getRadius());
        shapes.push_back(std::move(circle));
        return shapes;
    }

    std::vector<std::shared_ptr<sf::Sprite> > CircleModule::getSFSprites(sf::RenderWindow &window) const {
        return {};
    }

    std::vector<std::unique_ptr<sf::Text> > CircleModule::getSFTexts() const {
        return {};
    }

    const logic::Size &CircleModule::getSize() const {
        return size;
    }

    void CircleModule::setSize(const logic::Size &size) {
        CircleModule::size = size;
    }

    void CircleModule::update(ModularEntityView &subject) {
        setSize(subject.getSize());
    }

    void CircleModule::setFillColor(const sf::Color &color) {
        CircleModule::fillColor = color;
    }
} // renderer