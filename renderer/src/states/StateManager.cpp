//
// Created by runes on 3/11/2025.
//

#include "../../include/states/StateManager.h"

renderer::StateManager::StateManager(std::unique_ptr<IState> &&initialState,
                                     std::unique_ptr<IStateFactory> &&stateFactory) :
                                     stateFactory(std::move(stateFactory)) {
    stack.push(std::move(initialState));
}

void renderer::StateManager::processInput(sf::Event &event) {
    if (!stack.empty()) {
        stack.top()->processInput(event);
    }
}

void renderer::StateManager::draw(sf::RenderWindow &window) {
    if (!stack.empty()) {
        stack.top()->draw(window);
    }
}

void renderer::StateManager::update() {
    if (!stack.empty()) {
        stack.top()->update();
    }
}

void renderer::StateManager::pushState(std::unique_ptr<IState> &&state) {
    stack.push(std::move(state));
}

void renderer::StateManager::popState() {
    stack.pop();
}
