//
// Created by runes on 28/11/2025.
//

#include "game/states/GameOverState.h"
#include "SFML/Graphics.hpp"
#include "core/states/StateManager.h"

namespace renderer
{
    void GameOverState::update(StateManager& stateManager)
    {
    }

    void GameOverState::processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window)
    {
        if (event.type == sf::Event::KeyReleased || (firstEvent && event.type != sf::Event::KeyPressed))
        {
            keyReleased = true;
        }
        if (event.type == sf::Event::KeyPressed && keyReleased)
        {
            stateManager.popState();
        }
        firstEvent = false;
    }

    void GameOverState::draw(sf::RenderWindow& window, StateManager& stateManager)
    {
        gameOverLabel.draw(window);
        descrLabel.draw(window);
        currentScoreLabel.draw(window);
    }

    GameOverState::GameOverState(const std::shared_ptr<logic::Score>& score)
    {
        gameOverLabel.setCharacterSize(0.2);
        gameOverLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        gameOverLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        gameOverLabel.setPosition({0, 0.2});
        descrLabel.setCharacterSize(0.05);
        descrLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        descrLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        descrLabel.setPosition({0, -0.1});
        currentScoreLabel.setCharacterSize(0.05);
        currentScoreLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        currentScoreLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        currentScoreLabel.setPosition({0, 0});
        currentScoreLabel.setString("Your score is: " + std::to_string(score->getScoreCounter().getScore()));
    }
} // renderer
