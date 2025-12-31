//
// Created by runes on 3/11/2025.
//

#include "game/states/MenuState.h"
#include "core/handlers/IDrawHandler.h"
#include "core/states/IStateInputHandler.h"
#include "core/states/IStateUpdateHandler.h"
#include "core/utils/Camera.h"
#include "game/Game.h"
#include "core/factories/IStateFactory.h"
#include "game/states/LevelState.h"

namespace renderer
{
    void MenuState::update(StateManager& stateManager)
    {
    }

    void MenuState::processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            std::unique_ptr<IState> levelState = Game::getInstance()->getAppConfig().getFactoryCollection().
                                                                      getStateFactory()->createLevelState();
            stateManager.pushState(std::move(levelState));
        }
        playButton.processEvent(event, window);
    }

    void MenuState::draw(sf::RenderWindow& window, StateManager& stateManager)
    {
        if (!_fontLoaded)
        {
            std::string fileName = renderer::Game::getInstance()->getAppConfig().getConfigParser().getDefaultFontPath();
            if (!_font.loadFromFile(fileName))
            {
                throw std::runtime_error("Failed to load font from file: " + fileName);
            }
            _fontLoaded = true;
        }

        sf::Text title;
        title.setFont(_font);
        title.setString("PAC MAN");
        title.setCharacterSize(Camera::sizeY(0.2, window)); // Size in pixels
        title.setFillColor(sf::Color::Yellow);
        title.setStyle(sf::Text::Bold);
        title.setPosition(Camera::project(logic::Position{0, 0.5}, window));
        title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);

        sf::Text pressToPlay;
        pressToPlay.setFont(_font);
        pressToPlay.setString("Press Any Key to Play");
        pressToPlay.setCharacterSize(Camera::sizeY(0.1, window)); // Size in pixels
        pressToPlay.setFillColor(sf::Color::Yellow);
        pressToPlay.setPosition(Camera::project(logic::Position{0, -0.1}, window));
        pressToPlay.setOrigin(pressToPlay.getLocalBounds().width / 2, pressToPlay.getLocalBounds().height / 2);

        window.draw(title);
        window.draw(pressToPlay);
        playButton.setOnClick([this, &stateManager]() { this->onPlayButtonClick(stateManager); });
        playButton.draw(window);

        highScoreLabel.draw(window);
    }

    void MenuState::onManagerReActive()
    {
        const auto highScores = highScoreParser->getHighScores("resources/highscores.txt");
        std::string highScoreLabelText = "HighScores: \n";
        for (int i = 0; i < 5; i++)
        {
            highScoreLabelText += std::to_string(i + 1) + ". " + std::to_string(highScores.at(i)) + "\n";
        }
        highScoreLabel.setString(highScoreLabelText);
    }

    MenuState::MenuState()
    {
        playButton.setString("PLAY");
        playButton.setCharacterSize(0.1);
        playButton.setPosition({0, -0.3});
        const auto highScores = highScoreParser->getHighScores("resources/highscores.txt");
        std::string highScoreLabelText = "HighScores: \n";
        for (int i = 0; i < 5; i++)
        {
            highScoreLabelText += std::to_string(i + 1) + ". " + std::to_string(highScores.at(i)) + "\n";
        }
        highScoreLabel.setString(highScoreLabelText);
        highScoreLabel.setCharacterSize(0.05);
        highScoreLabel.setPosition({0, 0.3});
        highScoreLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
    }

    void MenuState::onPlayButtonClick(StateManager& stateManager) const
    {
        std::unique_ptr<IState> levelState = Game::getInstance()->getAppConfig().getFactoryCollection().
                                                                  getStateFactory()->createLevelState();
        stateManager.pushState(std::move(levelState));
    }
} // renderer
