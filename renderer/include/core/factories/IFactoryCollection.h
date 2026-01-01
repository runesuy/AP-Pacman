//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IFACTORYCOLLECTION_H
#define AP_PACMAN_IFACTORYCOLLECTION_H

#include "game/factories/StateManagerFactory.h"

namespace renderer
{
    class IFactoryCollection
    {
    public:
        virtual ~IFactoryCollection() = default;

        /**
         *
         * @return The factory for creating StateManager instances.
         */
        virtual std::unique_ptr<StateManagerFactory> getStateManagerFactory() = 0;

        /**
         *
         * @return The factory for creating game states.
         */
        virtual std::unique_ptr<IStateFactory> getStateFactory() = 0;
    };
} // renderer

#endif //AP_PACMAN_IFACTORYCOLLECTION_H
