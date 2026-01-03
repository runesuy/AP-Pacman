//
// Created by runes on 27/11/2025.
//

#include "game/states/PausedState.h"
#include "core/states/StateManager.h"

namespace renderer
{
    PausedState::PausedState()
    {
        pausedLabel.setString(pausedLabelText);
        pausedLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        pausedLabel.setCharacterSize(pausedLabelCharSize);
        pausedLabel.setPosition({0, 0.3});
        menuButton.setString(menuButtonText);
        menuButton.setCharacterSize(0.05);
        menuButton.setPosition({-0.3, 0});
        continueButton.setString(continueButtonText);
        continueButton.setCharacterSize(0.05);
        continueButton.setPosition({0.3, 0});
    }

    void PausedState::update(StateManager& stateManager)
    {
    }

    void PausedState::processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            stateManager.popState();
            return;
        }
        continueButton.processEvent(event, window);
        menuButton.processEvent(event, window);
    }

    void PausedState::draw(sf::RenderWindow& window, StateManager& stateManager)
    {
        pausedLabel.draw(window);
        menuButton.draw(window);
        continueButton.draw(window);
        continueButton.setOnClick([&stateManager]() { stateManager.popState(); });
        menuButton.setOnClick([&stateManager]()
        {
            stateManager.popState();
            stateManager.popState();
            return;
        });
    }
} // renderer
