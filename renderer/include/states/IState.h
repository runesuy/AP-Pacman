//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ISTATE_H
#define AP_PACMAN_ISTATE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace renderer {
    class IState {
    public:
        virtual void update()=0;

        virtual void processInput(sf::Event& event)=0;

        virtual void draw(sf::RenderWindow& window)=0;
    };
}


#endif //AP_PACMAN_ISTATE_H
