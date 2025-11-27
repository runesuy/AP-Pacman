//
// Created by runes on 3/11/2025.
//

#include "game/Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "core/states/IState.h"
#include "core/factories/IStateFactory.h"
#include "core/utils/Stopwatch.h"

int renderer::Game::run() {

    running = true;
    // load config file
    loadResources();

    std::unique_ptr<StateManager> stateManager = appConfig.getFactoryCollection().getStateManagerFactory()
            ->createStateManager(appConfig.getFactoryCollection().getStateFactory());


    //create sfml window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pacman");

    // game loop
    while (running && window.isOpen()) {
        logic::Stopwatch::getInstance()->tick();
        //--------- Process Input ---------
        sf::Event event{};
        bool cont = false;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                cont = true;
            }

            stateManager->processInput(event);
        }
        if (cont) continue;
        if (logic::Stopwatch::getInstance()->getDeltaTime() >0.1) continue;

        //--------- Update ---------
        stateManager->update();

        //--------- Render ---------
        window.clear(sf::Color::Black);
        stateManager->draw(window);
        window.display();
    }
    return 0;
}

renderer::Game::Game(renderer::IAppConfig& appConfig): appConfig(appConfig){
}

std::shared_ptr<renderer::Game> renderer::Game::initializeInstance(renderer::IAppConfig &appConfig) {
    if (_instance) {
        throw std::runtime_error("Game was already initialized.");
    }
    _instance = std::shared_ptr<Game>(new Game(appConfig));
    return _instance;
}

std::shared_ptr<renderer::Game> renderer::Game::getInstance() {
    if (!_instance) {
        throw std::runtime_error("Game must first be initialized.");
    }
    return _instance;
}

renderer::IAppConfig &renderer::Game::getAppConfig() const {
    return appConfig;
}

void renderer::Game::loadResources() {
    appConfig.getConfigParser().loadConfigFile();
    appConfig.getTextureParser().loadTextures(
            appConfig.getConfigParser().getSpriteSheetPath(),
            appConfig.getConfigParser().getTextureRects()
    );
}
