//
// Created by runes on 3/11/2025.
//

#include "../../include/utils/Camera.h"

int renderer::Camera::projectX(float posX, const sf::RenderWindow &window) {
    posX += 1.0f; // shift from [-1, 1] to [0, 2]
    posX /= 2.0f; // scale from [0, 2] to [0, 1]
    posX *= static_cast<float>(window.getSize().x); // scale to window width
    posX += (static_cast<float>(window.getSize().x)-posX) / 2.0f; // shift for zero centered x-axis
    return static_cast<int>(posX);
}

int renderer::Camera::projectX(const logic::Position &position, const sf::RenderWindow &window) {
    return projectX(position.getX(), window);
}

int renderer::Camera::projectY(float posY, const sf::RenderWindow &window) {
    posY += 1.0f; // shift from [-1, 1] to [0, 2]
    posY /= 2.0f; // scale from [0, 2] to [0, 1]
    posY *= static_cast<float>(window.getSize().y); // scale to window height
    return static_cast<int>(posY);
}

int renderer::Camera::projectY(const logic::Position &position, const sf::RenderWindow &window) {
    return projectY(position.getY(), window);;
}

std::tuple<int, int> renderer::Camera::project(const logic::Position &position, const sf::RenderWindow &window) {
    return {projectX(position.getX(), window), projectY(position.getY(), window)};
}
