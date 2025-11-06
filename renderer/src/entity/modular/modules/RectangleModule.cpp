//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "entity/modular/modules/RectangleModule.h"
#include "utils/Camera.h"

namespace renderer {
    std::vector<std::unique_ptr<sf::Shape>> RectangleModule::getSFShapes(sf::RenderWindow &window) const {
        std::vector<std::unique_ptr<sf::Shape>> shapes;
        auto rectangle = std::make_unique<sf::RectangleShape>();
        rectangle->setSize(Camera::project(size, window));
        rectangle->setPosition({0,0});
        rectangle->setFillColor(fillColor);
        rectangle->setOrigin(rectangle->getSize().x/2, rectangle->getSize().y/2);
        shapes.push_back(std::move(rectangle));
        return shapes;
    }

    std::vector<std::shared_ptr<sf::Sprite>> RectangleModule::getSFSprites() const {
        return {};
    }

    std::vector<std::unique_ptr<sf::Text>> RectangleModule::getSFTexts() const {
        return {};
    }

    const logic::Size &RectangleModule::getSize() const {
        return size;
    }

    void RectangleModule::setSize(const logic::Size &size) {
        RectangleModule::size = size;
    }

    void RectangleModule::update(std::shared_ptr<ModularEntityView> subject) {
        setSize(subject->getSize());
    }

    void RectangleModule::setFillColor(const sf::Color &color) {
        RectangleModule::fillColor = color;
    }
} // renderer