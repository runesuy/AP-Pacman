//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_BUTTON_H
#define AP_PACMAN_BUTTON_H

#include "core/drawable/DrawObject.h"
#include "core/drawable/ui/Label.h"
#include <SFML/Graphics.hpp>
#include <functional>

#include "core/world/space/Size.h"

namespace renderer
{
    /**
     * Class representing a UI button in the game.
     */
    class Button : public DrawObject
    {
        Label label;
        logic::Size::CoordinateType width = 0.3;
        std::function<void()> onClick;
        sf::RectangleShape rectangleShape;

    public:
        Button();

        void setPosition(const logic::Position& position) override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow& window) override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow& window) override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts(sf::RenderWindow& window) override;

        void setString(const std::string& str);

        void setFont(const sf::Font& font);

        void setCharacterSize(float size);

        void setWidth(logic::Size::CoordinateType width);

        void setOnClick(const std::function<void()>& onClick);

        void processEvent(const sf::Event& event, const sf::RenderWindow& window);
    };
} // renderer

#endif //AP_PACMAN_BUTTON_H
