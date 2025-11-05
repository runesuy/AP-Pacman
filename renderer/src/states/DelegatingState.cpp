//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/DelegatingState.h"
#include "states/IStateInputHandler.h"

void renderer::DelegatingState::update() {
    _updateHandler->update();
}

void renderer::DelegatingState::processInput(sf::Event &event, StateManager& stateManager) {
    _inputHandler->processInput(event, stateManager);
}

void renderer::DelegatingState::draw(sf::RenderWindow &window) {
    _drawHandler->draw(window);
}

renderer::DelegatingState::DelegatingState(std::unique_ptr<IUpdateHandler> &&updateHandler,
                                           std::unique_ptr<IStateInputHandler> &&inputHandler,
                                           std::unique_ptr<IDrawHandler> &&drawHandler) :
                                           _updateHandler(std::move(updateHandler)),
                                           _inputHandler(std::move(inputHandler)),
                                           _drawHandler(std::move(drawHandler)) {

}


