//
// Created by runes on 3/11/2025.
//

#include "../include/Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "states/IState.h"
#include "states/IStateFactory.h"

int renderer::Game::run() {

    running = true;
    std::unique_ptr<StateManager> stateManager = appConfig.getFactoryCollection().getStateManagerFactory()
            ->createStateManager(appConfig.getFactoryCollection().getStateFactory());

    // load config file
    appConfig.getConfigParser().loadConfigFile();

    //create sfml window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pacman");

    // game loop
    while (running && window.isOpen()) {

        //--------- Process Input ---------
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            stateManager->processInput(event);
        }

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
