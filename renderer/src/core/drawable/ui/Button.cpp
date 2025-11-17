//
// Created by rune-suy on 11/5/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "core/drawable/ui/Button.h"

namespace renderer {

    std::vector<std::unique_ptr<sf::Shape>> Button::getSFShapes(sf::RenderWindow &window) {
        std::vector<std::unique_ptr<sf::Shape>> shapes;

        auto rectShape = std::make_unique<sf::RectangleShape>();
        rectShape->setSize(sf::Vector2f(100.0f, 50.0f));
        rectShape->setFillColor(sf::Color::Blue);
        shapes.push_back(std::move(rectShape));
        return shapes;
    }

    std::vector<std::shared_ptr<sf::Sprite>> Button::getSFSprites(sf::RenderWindow &window) {
        return {};
    };

    std::vector<std::unique_ptr<sf::Text>> Button::getSFTexts(sf::RenderWindow &window) {
        return {};
    }
} // renderer