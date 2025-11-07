#include "game/Game.h"
#include "game/factories/DefaultFactoryCollection.h"
#include "game/configs/DefaultAppConfig.h"

int main() {
    renderer::DefaultAppConfig config;
    std::shared_ptr<renderer::Game> game = renderer::Game::initializeInstance(config);
    return game->run();
}
