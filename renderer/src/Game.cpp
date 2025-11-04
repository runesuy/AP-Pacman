//
// Created by runes on 3/11/2025.
//

#include "../include/Game.h"
#include "world/World.h"
#include "../include/states/StateManager.h"
#include "../include/states/MenuState.h"

void renderer::Game::run() {

    running = true;
    logic::World world;
    StateManager stateManager{std::make_unique<Game::InitialState>()};
    // game loop
    while (running) {
        // process input
        // update logic

        // update renderer
    }
}
