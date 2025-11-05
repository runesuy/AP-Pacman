//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_STATEMANAGER_H
#define AP_PACMAN_STATEMANAGER_H

#include <SFML/Window/Event.hpp>
#include "stack"
#include "memory"
#include "world/World.h"
#include <SFML/Graphics/RenderWindow.hpp>


namespace renderer {
    class MenuState;
    class IStateFactory;
    class IState;

    class StateManager {
        std::stack<std::unique_ptr<IState>> stack;
        std::unique_ptr<IStateFactory> stateFactory;
    public:
        explicit StateManager(std::unique_ptr<IState> &&initialState, std::unique_ptr<IStateFactory> &&stateFactory);

        /**
         * Process input events and forward them to the current state.
         * @param event The input event to process.
         */
        void processInput(sf::Event& event);

        /**
         * Draw the current state to the given window.
         * Forwards the draw call to the current state.
         * @param window
         */
        void draw(sf::RenderWindow& window);

        /**
         * Update the current state.
         * Forwards the update call to the current state.
         */
        void update();

        void pushState(std::unique_ptr<IState>&& state);

        void popState();
    };
}


#endif //AP_PACMAN_STATEMANAGER_H
