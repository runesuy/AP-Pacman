//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_DELEGATINGSTATE_H
#define AP_PACMAN_DELEGATINGSTATE_H
#include "IState.h"
#include <memory>
#include "core/handlers/IDrawHandler.h"
#include "IStateUpdateHandler.h"
#include "IStateInputHandler.h"
#include "IStateDrawHandler.h"

namespace renderer {

    class IStateFactory;

    class DelegatingState : public IState  {
        std::unique_ptr<IStateUpdateHandler> _updateHandler;
        std::unique_ptr<IStateInputHandler> _inputHandler;
        std::unique_ptr<IStateDrawHandler> _drawHandler;
    public:
        DelegatingState(std::unique_ptr<IStateUpdateHandler> &&updateHandler,
                        std::unique_ptr<IStateInputHandler> &&inputHandler,
                        std::unique_ptr<IStateDrawHandler> &&drawHandler);

        void update() override;

        void processInput(sf::Event &event, StateManager& stateManager) override;

        void draw(sf::RenderWindow &window) override;
    };
}
#endif //AP_PACMAN_DELEGATINGSTATE_H
