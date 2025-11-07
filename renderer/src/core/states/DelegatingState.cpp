//
// Created by rune-suy on 11/4/25.
//

#include "core/states/DelegatingState.h"
#include "core/states/IStateInputHandler.h"
#include "core/handlers/IDrawHandler.h"
#include "core/states/IStateUpdateHandler.h"


void renderer::DelegatingState::update() {
    _updateHandler->update(*this);
}

void renderer::DelegatingState::processInput(sf::Event &event, StateManager& stateManager) {
    _inputHandler->processInput(event, stateManager, *this);
}

void renderer::DelegatingState::draw(sf::RenderWindow &window) {
    _drawHandler->draw(window);
}

renderer::DelegatingState::DelegatingState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                                           std::unique_ptr<IStateInputHandler> &&inputHandler,
                                           std::unique_ptr<IDrawHandler> &&drawHandler) :
                                           _updateHandler(std::move(updateHandler)),
                                           _inputHandler(std::move(inputHandler)),
                                           _drawHandler(std::move(drawHandler)) {

}


