//
// Created by runes on 3/11/2025.
//

#include <iostream>
#include "core/utils/Camera.h"

float renderer::Camera::projectX(logic::Position::CoordinateType posX, const sf::RenderWindow &window) {
    const unsigned int smallestSide = std::min(window.getSize().x, window.getSize().y);
    posX += 1.0f; // shift from [-1, 1] to [0, 2]
    posX /= 2.0f; // scale from [0, 2] to [0, 1]
    posX *= smallestSide; // scale to window height
    posX += std::max(0.0f, (static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().y))) / 2.0f;
    // shift for zero centered x-axis
    return posX;
}

float renderer::Camera::projectX(const logic::Position &position, const sf::RenderWindow &window) {
    return projectX(position.getX(), window);
}

float renderer::Camera::projectY(logic::Position::CoordinateType posY, const sf::RenderWindow &window) {
    posY *= -1.0f; // invert y-axis
    const unsigned int smallestSide = std::min(window.getSize().x, window.getSize().y);
    posY += 1.0f; // shift from [-1, 1] to [0, 2]
    posY /= 2.0f; // scale from [0, 2] to [0, 1]
    posY *= static_cast<float>(smallestSide); // scale to window height
    posY += std::max(0.0f, (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().x))) / 2.0f;
    // shift for zero centered x-axis
    return posY;
}

float renderer::Camera::projectY(const logic::Position &position, const sf::RenderWindow &window) {
    return projectY(position.getY(), window);;
}

sf::Vector2<float> renderer::Camera::project(const logic::Position &position, const sf::RenderWindow &window) {
    return {projectX(position.getX(), window), projectY(position.getY(), window)};
}

sf::Vector2<float> renderer::Camera::project(const logic::Size &size, const sf::RenderWindow &window) {
    return {sizeX(size.getX(), window), sizeY(size.getY(), window)};
}

float renderer::Camera::sizeX(logic::Position::CoordinateType sizeX, const sf::RenderWindow &window) {
    float center = projectX(-1, window);
    float corner = projectX(sizeX - 1, window);
    float result = center - corner;
    result = -result;
    return result;
}

float renderer::Camera::sizeY(logic::Position::CoordinateType sizeY, const sf::RenderWindow &window) {
    float center = projectY(-1, window);
    float corner = projectY(sizeY - 1, window);
    float result = center - corner;
    return result;
}