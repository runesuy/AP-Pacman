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

    template<typename Derived>
    class DelegatingState : public IState  {
        std::unique_ptr<IStateUpdateHandler<Derived>> _updateHandler;
        std::unique_ptr<IStateInputHandler<Derived>> _inputHandler;
        std::unique_ptr<IStateDrawHandler<Derived>> _drawHandler;
    public:
        DelegatingState(std::unique_ptr<IStateUpdateHandler<Derived>> &&updateHandler,
                        std::unique_ptr<IStateInputHandler<Derived>> &&inputHandler,
                        std::unique_ptr<IStateDrawHandler<Derived>> &&drawHandler);

        void update() override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;
    };

    template<typename Derived>
    void renderer::DelegatingState<Derived>::update() {
        _updateHandler->update(static_cast<Derived&>(*this));
    }

    template<typename Derived>
    void renderer::DelegatingState<Derived>::processInput(sf::Event &event, StateManager &stateManager,
                                                          const sf::RenderWindow &window) {
        _inputHandler->processInput(event, stateManager, static_cast<Derived &>(*this), window);
    }

    template<typename Derived>
    void renderer::DelegatingState<Derived>::draw(sf::RenderWindow &window, StateManager &stateManager) {
        _drawHandler->draw(window, static_cast<Derived &>(*this), stateManager);
    }

    template<typename Derived>
    renderer::DelegatingState<Derived>::DelegatingState(std::unique_ptr<IStateUpdateHandler<Derived>> &&updateHandler,
                                               std::unique_ptr<IStateInputHandler<Derived>> &&inputHandler,
                                               std::unique_ptr<IStateDrawHandler<Derived>> &&drawHandler) :
            _updateHandler(std::move(updateHandler)),
            _inputHandler(std::move(inputHandler)),
            _drawHandler(std::move(drawHandler)) {

    }
}
#endif //AP_PACMAN_DELEGATINGSTATE_H
