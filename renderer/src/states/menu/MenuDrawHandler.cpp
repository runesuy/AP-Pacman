//
// Created by rune-suy on 11/4/25.
//

#include "../../../include/states/menu/MenuDrawHandler.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "utils/Camera.h"

void renderer::MenuDrawHandler::draw(sf::RenderWindow &window) {
    if (!_fontLoaded) {
        std::string fileName = renderer::Game::getInstance()->getAppConfig().getConfigParser().getDefaultFontPath();
        if (!_font.loadFromFile(fileName)) {
            throw std::runtime_error("Failed to load font from file: " + fileName);
        }
        _fontLoaded = true;
    }

    sf::Text text;
    text.setFont(_font);

    text.setString("PAC MAN");

    text.setCharacterSize(50);      // Size in pixels
    text.setFillColor(sf::Color::Yellow);
    text.setStyle(sf::Text::Bold );

    text.setPosition(Camera::projectX({0,0}, window), Camera::projectY({0,0}, window));
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);

    sf::RectangleShape rect;
    rect.setPosition(Camera::project({-1,1}, window));
    rect.setFillColor(sf::Color::Red);
    rect.setSize(Camera::project({1,-1}, window)-Camera::project({-1,1}, window));
    window.draw(rect);

    window.draw(text);
}
