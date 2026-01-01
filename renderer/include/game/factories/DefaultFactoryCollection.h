//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DEFAULTFACTORYCOLLECTION_H
#define AP_PACMAN_DEFAULTFACTORYCOLLECTION_H

#include "core/factories/IFactoryCollection.h"

namespace renderer
{
    /**
     * Default implementation of the factory collection interface.
     */
    class DefaultFactoryCollection : public IFactoryCollection
    {
    public:
        std::unique_ptr<StateManagerFactory> getStateManagerFactory() override;

        std::unique_ptr<IStateFactory> getStateFactory() override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTFACTORYCOLLECTION_H
