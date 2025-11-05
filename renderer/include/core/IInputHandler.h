//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_IINPUTHANDLER_H
#define AP_PACMAN_IINPUTHANDLER_H

#include <SFML/Window/Event.hpp>

namespace renderer {

    class IInputHandler {
    public:
        virtual void processInput(sf::Event& event)=0;

        virtual ~IInputHandler() = default;
    };

} // renderer

#endif //AP_PACMAN_IINPUTHANDLER_H
