//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/DelegatingState.h"
#include "states/IStateInputHandler.h"
#include "core/IDrawHandler.h"
#include "states/IStateUpdateHandler.h"


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
                                           std::unique_ptr<logic::IDrawHandler> &&drawHandler) :
                                           _updateHandler(std::move(updateHandler)),
                                           _inputHandler(std::move(inputHandler)),
                                           _drawHandler(std::move(drawHandler)) {

}


