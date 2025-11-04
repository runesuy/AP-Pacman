//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DELEGATINGSTATE_H
#define AP_PACMAN_DELEGATINGSTATE_H
#include "IState.h"
#include "../core/IUpdateHandler.h"
#include "../core/IInputHandler.h"
#include "../core/IDrawHandler.h"
#include <memory>

namespace renderer {
    class DelegatingState : public IState {

        std::unique_ptr<IUpdateHandler> _updateHandler;
        std::unique_ptr<IInputHandler> _inputHandler;
        std::unique_ptr<IDrawHandler> _drawHandler;
    public:
        DelegatingState(std::unique_ptr<IUpdateHandler> &&updateHandler,
                        std::unique_ptr<IInputHandler> &&inputHandler,
                        std::unique_ptr<IDrawHandler> &&drawHandler);

        void update() override;

        void processInput(sf::Event &event) override;

        void draw(sf::RenderWindow &window) override;
    };
}
#endif //AP_PACMAN_DELEGATINGSTATE_H
