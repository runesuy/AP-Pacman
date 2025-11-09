//
// Created by rune-suy on 11/4/25.
//

#include "game/states/menu/MenuDrawHandler.h"
#include "game/Game.h"
#include <SFML/Graphics.hpp>
#include "core/utils/Camera.h"

void renderer::MenuDrawHandler::draw(sf::RenderWindow &window, IState& state) {
    if (!_fontLoaded) {
        std::string fileName = renderer::Game::getInstance()->getAppConfig().getConfigParser().getDefaultFontPath();
        if (!_font.loadFromFile(fileName)) {
            throw std::runtime_error("Failed to load font from file: " + fileName);
        }
        _fontLoaded = true;
    }

    sf::Text title;
    title.setFont(_font);
    title.setString("PAC MAN");
    title.setCharacterSize(Camera::sizeY(0.2, window));      // Size in pixels
    title.setFillColor(sf::Color::Yellow);
    title.setStyle(sf::Text::Bold );
    title.setPosition(Camera::project(logic::Position{0, 0.5}, window));
    title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);

    sf::Text pressToPlay;
    pressToPlay.setFont(_font);
    pressToPlay.setString("Press Any Key to Play");
    pressToPlay.setCharacterSize(Camera::sizeY(0.1, window));      // Size in pixels
    pressToPlay.setFillColor(sf::Color::Yellow);
    pressToPlay.setPosition(Camera::project(logic::Position{0, 0}, window));
    pressToPlay.setOrigin(pressToPlay.getLocalBounds().width / 2, pressToPlay.getLocalBounds().height / 2);

    /*sf::RectangleShape rect;
    rect.setPosition(Camera::project(logic::Position{-1,1}, window));
    rect.setFillColor(sf::Color::Red);
    rect.setSize(Camera::project(logic::Size{2,2}, window));
    window.draw(rect);*/
    // Testing Rect

    window.draw(title);
    window.draw(pressToPlay);
}
