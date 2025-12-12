//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELSTATE_H
#define AP_PACMAN_LEVELSTATE_H

#include "core/states/DelegatingState.h"
#include "core/world/World.h"
#include "core/world/WorldView.h"

namespace renderer {

    /**
     * State representing the main gameplay level.
     * Loads a map on the screen and lets player play the game.
     */
    class LevelState final : public IState {
        std::unique_ptr<logic::World> _world;
        std::shared_ptr<WorldView> _worldView;

    public:
        LevelState();
        explicit LevelState(const std::shared_ptr<logic::Score>& score);

        std::unique_ptr<logic::World> &getWorld();

        [[nodiscard]] const std::shared_ptr<WorldView> &getWorldView() const;

        void update(StateManager &stateManager) override;

        void processInput(sf::Event &event, StateManager &stateManager, const sf::RenderWindow &window) override;

        void draw(sf::RenderWindow &window, StateManager &stateManager) override;

    };

} // renderer

#endif //AP_PACMAN_LEVELSTATE_H
