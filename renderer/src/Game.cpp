//
// Created by runes on 3/11/2025.
//

#include "../include/Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

int renderer::Game::run() {

    running = true;
    std::unique_ptr<StateManager> stateManager = factoryCollection.getStateManagerFactory()->createStateManager();

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

            stateManager->processInput(event);
        }

        //--------- Update ---------
        stateManager->update();

        //--------- Render ---------
        window.clear(sf::Color::Black);
        stateManager->draw(window);
    }
    return 0;
}

renderer::Game::Game(renderer::IFactoryCollection &factoryCollection) : factoryCollection(factoryCollection){

}
