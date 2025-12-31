//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/DefaultFactoryCollection.h"
#include "game/factories/DefaultStateFactory.h"
#include "game/factories/DefaultEntityFactory.h"

namespace renderer
{
    std::unique_ptr<StateManagerFactory> DefaultFactoryCollection::getStateManagerFactory()
    {
        return std::make_unique<StateManagerFactory>();
    }

    std::unique_ptr<IStateFactory> DefaultFactoryCollection::getStateFactory()
    {
        return std::make_unique<DefaultStateFactory>();
    }
} // renderer
