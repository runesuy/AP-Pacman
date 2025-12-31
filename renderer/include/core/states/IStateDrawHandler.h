//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_ISTATEDRAWHANDLER_H
#define AP_PACMAN_ISTATEDRAWHANDLER_H

#include "core/handlers/IDrawHandler.h"
#include "IState.h"

namespace renderer
{
    template <typename DerivedState>
    class IStateDrawHandler : public IDrawHandler
    {
    public:
        void draw(sf::RenderWindow& window) final
        {
        };

        virtual void draw(sf::RenderWindow& window, DerivedState& state, StateManager& stateManager) = 0;
    };
} // renderer

#endif //AP_PACMAN_ISTATEDRAWHANDLER_H
