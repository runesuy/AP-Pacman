#include <iostream>
#include "../include/Game.h"
#include "config/DefaultFactoryCollection.h"
#include "config/DefaultAppConfig.h"

int main() {
    renderer::DefaultAppConfig config;
    std::shared_ptr<renderer::Game> game = renderer::Game::initializeInstance(config);
    return game->run();
}
