//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IFACTORYCOLLECTION_H
#define AP_PACMAN_IFACTORYCOLLECTION_H

#include "StateManagerFactory.h"

namespace renderer {

    class IFactoryCollection {
    public:
        virtual std::unique_ptr<StateManagerFactory> getStateManagerFactory() = 0;

        virtual std::unique_ptr<IStateFactory> getStateFactory() = 0;
    };

} // renderer

#endif //AP_PACMAN_IFACTORYCOLLECTION_H
