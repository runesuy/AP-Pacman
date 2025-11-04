//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/StateManagerFactory.h"
#include "../../include/states/DefaultStateFactory.h"

namespace renderer {
    std::unique_ptr<StateManager> StateManagerFactory::createStateManager() {
        auto factory = std::make_unique<DefaultStateFactory>();
        auto menuState = factory->createMenuState();
        return std::make_unique<StateManager>(std::move(menuState),std::move(factory));
    }
} // renderer