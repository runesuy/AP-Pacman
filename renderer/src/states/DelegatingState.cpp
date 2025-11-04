//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/DelegatingState.h"

void renderer::DelegatingState::update() {
    _updateHandler->update();
}

void renderer::DelegatingState::processInput(sf::Event &event) {
    _inputHandler->processInput(event);
}

void renderer::DelegatingState::draw(sf::RenderWindow &window) {
    _drawHandler->draw(window);
}

renderer::DelegatingState::DelegatingState(std::unique_ptr<IUpdateHandler> &&updateHandler,
                                           std::unique_ptr<IInputHandler> &&inputHandler,
                                           std::unique_ptr<IDrawHandler> &&drawHandler) :
                                           _updateHandler(std::move(updateHandler)),
                                           _inputHandler(std::move(inputHandler)),
                                           _drawHandler(std::move(drawHandler)) {

}


