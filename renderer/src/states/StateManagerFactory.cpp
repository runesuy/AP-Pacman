//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/StateManagerFactory.h"
#include "../../include/states/DefaultStateFactory.h"

namespace renderer {
    std::unique_ptr<StateManager> StateManagerFactory::createStateManager(std::unique_ptr<IStateFactory> stateFactory) {
        auto menuState = stateFactory->createMenuState();
        return std::make_unique<StateManager>(std::move(menuState),std::move(stateFactory));
    }
} // renderer