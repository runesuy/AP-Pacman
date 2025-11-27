//
// Created by rune-suy on 11/5/25.
//

#include "game/states/level/LevelInputHandler.h"
#include "game/states/level/LevelState.h"
#include "game/WorldCommand.h"

namespace renderer {
    void LevelInputHandler::processInput(sf::Event &event, StateManager &stateManager, IState &state) {
        auto& levelState = dynamic_cast<LevelState&>(state);
        switch (event.type) {
            case sf::Event::KeyPressed:
                levelState.getWorld()->receiveCommand(logic::WorldCommand::ON_KEY_PRESS);
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        levelState.getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_LEFT);
                        break;
                    case sf::Keyboard::Right:
                        levelState.getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_RIGHT);
                        break;
                    case sf::Keyboard::Up:
                        levelState.getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_UP);
                        break;
                    case sf::Keyboard::Down:
                        levelState.getWorld()->sendCommandTo<logic::PlayerModel>(logic::EntityCommand::TURN_DOWN);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
} // renderer