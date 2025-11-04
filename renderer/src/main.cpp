#include <iostream>
#include "../include/Game.h"
#include "../include/DefaultFactoryCollection.h"

int main() {
    renderer::DefaultFactoryCollection factoryCollection{};
    renderer::Game game{factoryCollection};
    return game.run();
}
