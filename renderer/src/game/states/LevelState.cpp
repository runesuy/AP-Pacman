//
// Created by rune-suy on 11/5/25.
//

#include "game/states/LevelState.h"

#include <memory>
#include "core/states/IStateInputHandler.h"
#include "game/Game.h"
#include "game/factories/DefaultEntityFactory.h"
#include "game/WorldCommand.h"
#include "core/factories/IStateFactory.h"
#include "game/states/GameOverState.h"
#include "game/states/VictoryState.h"

namespace renderer {
    LevelState::LevelState() {
        auto &logicConfig = Game::getInstance()->getAppConfig().getLogicConfig();
        auto entityFactory = logicConfig.getEntityFactory();
        auto defaultFactory = std::dynamic_pointer_cast<DefaultEntityFactory>(entityFactory);
        _worldView = std::make_shared<WorldView>();
        if (defaultFactory) {
            defaultFactory->setViewTarget(_worldView);
        }
        _world = std::make_unique<logic::World>(logicConfig);
        _world->addObserver(_worldView);
    }

    std::unique_ptr<logic::World> &LevelState::getWorld() {
        return _world;
    }

    const std::shared_ptr<WorldView> &LevelState::getWorldView() const {
        return _worldView;
    }

    void LevelState::update(StateManager &stateManager) {
        getWorld()->update();
        if (getWorld()->isGameOver()) {
            getWorld()->getScore()->getScoreCounter().saveHighScores();
            stateManager.replaceState(std::make_unique<GameOverState>(getWorld()->getScore()));
            return;
        }
        if (getWorld()->levelComplete()){
            stateManager.replaceState(std::make_unique<VictoryState>(getWorld()->getScore()));
            return;
        }
    }

    void LevelState::processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                getWorld()->receiveCommand(logic::WorldCommand::ON_KEY_PRESS);
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_LEFT);
                        break;
                    case sf::Keyboard::Right:
                        getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_RIGHT);
                        break;
                    case sf::Keyboard::Up:
                        getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_UP);
                        break;
                    case sf::Keyboard::Down:
                        getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_DOWN);
                        break;
                    case sf::Keyboard::Escape:
                        stateManager.pushState(
                                Game::getInstance()->getAppConfig().getFactoryCollection().getStateFactory()->createPausedState());
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    void LevelState::draw(sf::RenderWindow &window, StateManager &stateManager) {
        getWorldView()->draw(window);
    }

    LevelState::LevelState(const std::shared_ptr<logic::Score> &score) {
        auto &logicConfig = Game::getInstance()->getAppConfig().getLogicConfig();
        auto entityFactory = logicConfig.getEntityFactory();
        auto defaultFactory = std::dynamic_pointer_cast<DefaultEntityFactory>(entityFactory);
        _worldView = std::make_shared<WorldView>();
        if (defaultFactory) {
            defaultFactory->setViewTarget(_worldView);
        }
        _world = std::make_unique<logic::World>(logicConfig, score);
        _world->addObserver(_worldView);
    }
} // renderer