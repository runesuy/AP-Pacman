//
// Created by runes on 28/11/2025.
//

#include "game/states/VictoryState.h"
#include "core/states/StateManager.h"
#include "game/states/LevelState.h"

namespace renderer {
    void VictoryState::update(StateManager &stateManager) {
    }

    void VictoryState::processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) {
        if (event.type == sf::Event::KeyPressed) {
            stateManager.replaceState(std::make_unique<LevelState>(passToNextLevel));
        }
    }

    void VictoryState::draw(sf::RenderWindow &window, StateManager &stateManager) {
        currentScoreLabel.setString(currentScoreLabelPref + std::to_string(passToNextLevel->getScoreCounter().getScore()));
        victoryLabel.draw(window);
        descrLabel.draw(window);
        currentScoreLabel.draw(window);
    }

    VictoryState::VictoryState(const std::shared_ptr<logic::Score> &passToNextLevel) {
        this->passToNextLevel = passToNextLevel;
        victoryLabel.setCharacterSize(0.2);
        victoryLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        victoryLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        victoryLabel.setPosition({0, 0.2});
        descrLabel.setCharacterSize(0.05);
        descrLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        descrLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        descrLabel.setPosition({0, -0.1});
        currentScoreLabel.setCharacterSize(0.05);
        currentScoreLabel.setVerticalOrigin(Label::VerticalOriginType::BOTTOM);
        currentScoreLabel.setHorizontalOrigin(Label::HorizontalOriginType::MIDDLE);
        currentScoreLabel.setPosition({0, 0});
    }
} // renderer