//
// Created by rune-suy on 11/5/25.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "core/drawable/ui/Button.h"
#include "core/utils/Camera.h"

namespace renderer {

    std::vector<std::unique_ptr<sf::Shape>> Button::getSFShapes(sf::RenderWindow &window) {
        std::vector<std::unique_ptr<sf::Shape>> shapes;

        rectangleShape.setSize(Camera::project(logic::Size{width, label.getCharacterSize()}, window));
        rectangleShape.setOrigin(rectangleShape.getLocalBounds().width / 2, 0);
        shapes.push_back(std::make_unique<sf::RectangleShape>(rectangleShape));
        return shapes;
    }

    std::vector<std::shared_ptr<sf::Sprite>> Button::getSFSprites(sf::RenderWindow &window) {
        return {};
    };

    std::vector<std::unique_ptr<sf::Text>> Button::getSFTexts(sf::RenderWindow &window) {
        return label.getSFTexts(window);
    }

    void Button::setString(const std::string &str) {
        label.setString(str);
    }

    void Button::setFont(const sf::Font &font) {
        label.setFont(font);
    }

    void Button::setCharacterSize(float size) {
        label.setCharacterSize(size);
    }

    Button::Button() {
        label.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        label.setVerticalOrigin(Label::VerticalOriginType::MIDDLE);
        rectangleShape.setFillColor(sf::Color::Blue);
    }

    void Button::setPosition(const logic::Position &position) {
        label.setPosition(position);
        DrawObject::setPosition(position);
    }

    void Button::setWidth(logic::Size::CoordinateType width) {
        this->width = width;
    }

    void Button::setOnClick(const std::function<void()> &onClick) {
        Button::onClick = onClick;
    }

    void Button::processEvent(const sf::Event &event, const sf::RenderWindow &window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            auto pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            // globalBounds is in position system
            // convert to sfml system
            sf::RectangleShape dummyRect = rectangleShape;
            dummyRect.setPosition(rectangleShape.getPosition() + Camera::project(getPosition(), window));
            auto globalBounds = dummyRect.getGlobalBounds();
            if (globalBounds.contains(pos.x, pos.y)) {
                onClick();
            }
        }
    }
} // renderer