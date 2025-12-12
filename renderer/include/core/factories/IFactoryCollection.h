//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IFACTORYCOLLECTION_H
#define AP_PACMAN_IFACTORYCOLLECTION_H

#include "game/factories/StateManagerFactory.h"

namespace renderer {
    class IFactoryCollection {
    public:
        virtual ~IFactoryCollection() = default;

        virtual std::unique_ptr<StateManagerFactory> getStateManagerFactory() = 0;

        virtual std::unique_ptr<IStateFactory> getStateFactory() = 0;
    };
} // renderer

#endif //AP_PACMAN_IFACTORYCOLLECTION_H
