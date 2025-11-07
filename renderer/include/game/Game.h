//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_GAME_H
#define AP_PACMAN_GAME_H

#include <SFML/Window/Event.hpp>
#include "core/states/StateManager.h"
#include "world/World.h"
#include "core/factories/IFactoryCollection.h"
#include "core/parser/IConfigParser.h"
#include "core/config/IAppConfig.h"
#include "core/drawable/DrawCollection.h"

namespace renderer {
    /**
     * Singleton
     * Manages the representation side of the game, such as:
     * - Game loop
     * - Factory creation
     * - Processing user interaction
     */
    class Game {
        /**
         * The initial state the StateManager starts in
         */
        using InitialState = MenuState;

        bool running=false;

        /**
         * All the game configurations
         */
        IAppConfig& appConfig;

        inline static std::shared_ptr<Game> _instance;

        explicit Game(IAppConfig& appConfig);

        DrawCollection drawCollection;
    public:
        Game(Game&&) noexcept = delete;
        Game(Game&) = delete;
        Game operator=(Game&&) noexcept = delete;
        Game operator=(Game&) = delete;
        /**
         * Start the game.
         */
        int run();

        /**
         * Call to initialize the instance with a IConfig.
         * @return
         */
        static std::shared_ptr<Game> initializeInstance(IAppConfig& appConfig);

        /**
         * Get active instance.
         * @return
         */
        static std::shared_ptr<Game> getInstance();

        [[nodiscard]] IAppConfig &getAppConfig() const;

        [[nodiscard]] const DrawCollection &getDrawCollection() const;

        DrawCollection &getDrawCollection();
    };
}


#endif //AP_PACMAN_GAME_H
