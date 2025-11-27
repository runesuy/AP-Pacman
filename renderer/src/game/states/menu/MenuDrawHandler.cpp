//
// Created by rune-suy on 11/4/25.
//

#include "game/states/menu/MenuDrawHandler.h"
#include "game/Game.h"
#include <SFML/Graphics.hpp>
#include "core/utils/Camera.h"
#include "core/factories/IStateFactory.h"
#include "game/states/level/LevelState.h"

void renderer::MenuDrawHandler::draw(sf::RenderWindow &window, MenuState& state, StateManager& stateManager) {
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

    window.draw(title);
    window.draw(pressToPlay);
    playButton.setOnClick([this, &stateManager](){this->onPlayButtonClick(stateManager);});
    playButton.draw(window);
}

renderer::MenuDrawHandler::MenuDrawHandler() {
    playButton.setString("PLAY");
    playButton.setCharacterSize(0.1);
    playButton.setPosition({0,-0.2});
}

void renderer::MenuDrawHandler::onPlayButtonClick(StateManager& stateManager) const {
    std::unique_ptr<IState> levelState = Game::getInstance()->getAppConfig().getFactoryCollection().getStateFactory()->createLevelState();
    stateManager.pushState(std::move(levelState));
}
