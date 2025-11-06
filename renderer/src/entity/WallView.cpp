//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "entity/WallView.h"
#include "utils/Camera.h"

namespace renderer {
    std::vector<std::unique_ptr<sf::Shape>> WallView::getSFShapes(sf::RenderWindow &window) {
        std::vector<std::unique_ptr<sf::Shape>> shapes;
        auto rectangle = std::make_unique<sf::RectangleShape>();
        rectangle->setSize(Camera::project(getSize(), window));
        rectangle->setPosition({0,0});
        rectangle->setFillColor(sf::Color::Red);
        shapes.push_back(std::move(rectangle));
        return shapes;
    }

    std::vector<std::unique_ptr<sf::Sprite>> WallView::getSFSprites() {
        return std::vector<std::unique_ptr<sf::Sprite>>();
    }

    std::vector<std::unique_ptr<sf::Text>> WallView::getSFTexts() {
        return std::vector<std::unique_ptr<sf::Text>>();
    }

    void WallView::update(std::shared_ptr<logic::WallModel> subject) {
        setPosition(subject->getPosition());
        setSize(subject->getSize());
    }

    WallView::WallView() {}

} // renderer