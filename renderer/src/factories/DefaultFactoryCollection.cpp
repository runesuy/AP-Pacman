//
// Created by rune-suy on 11/4/25.
//

#include "factories/DefaultFactoryCollection.h"
#include "factories/DefaultStateFactory.h"
#include "factories/DefaultEntityFactory.h"

namespace renderer {
    std::unique_ptr<StateManagerFactory> DefaultFactoryCollection::getStateManagerFactory() {
        return std::make_unique<StateManagerFactory>();
    }

    std::unique_ptr<IStateFactory> DefaultFactoryCollection::getStateFactory() {
        return std::make_unique<DefaultStateFactory>();
    }
} // renderer