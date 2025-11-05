//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ISTATEINPUTHANDLER_H
#define AP_PACMAN_ISTATEINPUTHANDLER_H

#include "core/IInputHandler.h"
#include "IStateFactory.h"
#include "states/StateManager.h"

namespace renderer {
    class IStateInputHandler : public IInputHandler{
    public:
        virtual void processInput(sf::Event& event, StateManager &factory)=0;

        void processInput(sf::Event &event) override {};
    };
}
#endif //AP_PACMAN_ISTATEINPUTHANDLER_H
