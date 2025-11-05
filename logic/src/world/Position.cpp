//
// Created by runes on 3/11/2025.
//

#include "world/Position.h"
#include <stdexcept>

logic::Position::Position(float x, float y): x(x), y(y) {
    if (x < -1 || x > 1) {
        throw std::invalid_argument("value of x should be between -1 and 1");
    }
    if (y < -1 || y > 1) {
        throw std::invalid_argument("value of y should be between -1 and 1");
    }
}

float logic::Position::getX() const {
    return x;
}

void logic::Position::setX(float x) {
    if (x < -1 || x > 1) {
        throw std::invalid_argument("value of x should be between -1 and 1");
    }
    Position::x = x;
}

float logic::Position::getY() const {
    return y;
}

void logic::Position::setY(float y) {
    if (y < -1 || y > 1) {
        throw std::invalid_argument("value of y should be between -1 and 1");
    }
    Position::y = y;
}