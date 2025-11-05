//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DELEGATINGSTATE_H
#define AP_PACMAN_DELEGATINGSTATE_H
#include "IState.h"
#include "../core/IUpdateHandler.h"
#include "../core/IDrawHandler.h"
#include <memory>
#include "IStateInputHandler.h"

namespace renderer {

    class IStateFactory;
    class IStateInputHandler;

    class DelegatingState : public IState {

        std::unique_ptr<IUpdateHandler> _updateHandler;
        std::unique_ptr<IStateInputHandler> _inputHandler;
        std::unique_ptr<IDrawHandler> _drawHandler;
    public:
        DelegatingState(std::unique_ptr<IUpdateHandler> &&updateHandler,
                        std::unique_ptr<IStateInputHandler> &&inputHandler,
                        std::unique_ptr<IDrawHandler> &&drawHandler);

        void update() override;

        void processInput(sf::Event &event, StateManager& stateManager) override;

        void draw(sf::RenderWindow &window) override;
    };
}
#endif //AP_PACMAN_DELEGATINGSTATE_H
