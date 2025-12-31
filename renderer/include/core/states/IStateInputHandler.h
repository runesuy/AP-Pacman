//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ISTATEINPUTHANDLER_H
#define AP_PACMAN_ISTATEINPUTHANDLER_H

#include "core/handlers/IInputHandler.h"
#include "SFML/Graphics.hpp"

namespace renderer
{
    class StateManager;
    class IState;

    /**
     * Interface for handling input specific to a game state.
     */
    template <typename DerivedState>
    class IStateInputHandler : public renderer::IInputHandler
    {
    public:
        virtual void processInput(sf::Event& event, StateManager& stateManager, DerivedState& state,
                                  const sf::RenderWindow& window) =0;

        void processInput(sf::Event& event) override
        {
        };
    };
}
#endif //AP_PACMAN_ISTATEINPUTHANDLER_H
