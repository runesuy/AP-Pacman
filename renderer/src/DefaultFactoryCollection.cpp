//
// Created by rune-suy on 11/4/25.
//

#include "../include/DefaultFactoryCollection.h"
#include "../include/states/DefaultStateFactory.h"

namespace renderer {
    std::unique_ptr<StateManagerFactory> DefaultFactoryCollection::getStateManagerFactory() {
        return std::make_unique<StateManagerFactory>();
    }

    std::unique_ptr<IStateFactory> DefaultFactoryCollection::getStateFactory() {
        return std::make_unique<DefaultStateFactory>();
    }
} // renderer