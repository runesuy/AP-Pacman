//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ISTATE_H
#define AP_PACMAN_ISTATE_H


#include <SFML/Graphics/RenderWindow.hpp>

namespace renderer
{
    class StateManager;

    /**
     * Interface for game states, defining methods for updating, processing input, and drawing.
     */
    class IState
    {
    public:
        /**
         * Update the state logic.
         */
        virtual void update(StateManager& stateManager) =0;

        /**
         * Process input events for the state.
         * @param event
         * @param stateManager
         */
        virtual void processInput(sf::Event& event, StateManager& stateManager, const sf::RenderWindow& window) =0;

        /**
         * Draw the state onto the provided render window.
         * @param window
         */
        virtual void draw(sf::RenderWindow& window, StateManager& stateManager) =0;

        /**
         * Called when the state becomes active again after being paused or another state is popped.
         */
        virtual void onManagerReActive()
        {
        }

        virtual ~IState() = default;
    };
}


#endif //AP_PACMAN_ISTATE_H
