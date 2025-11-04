//
// Created by runes on 3/11/2025.
//

#include "../../include/states/StateManager.h"

renderer::StateManager::StateManager(std::unique_ptr<IState> &&initialState) {
    stack.push(std::move(initialState));
}
