//
// Created by rune-suy on 11/5/25.
//

#include "core/world/Size.h"
#include "stdexcept"

namespace logic {
    float Size::getX() const {
        return width;
    }

    void Size::setX(float x) {
        if (x < 0) {
            throw std::invalid_argument("width cannot be negative");
        }
        width = x;
    }

    float Size::getY() const {
        return height;
    }

    void Size::setY(float y) {
        if (y < 0) {
            throw std::invalid_argument("height cannot be negative");
        }
        height = y;
    }

    Size::Size(float x, float y) {
        if (x < 0) {
            throw std::invalid_argument("width cannot be negative");
        }
        width = x;
        if (y < 0) {
            throw std::invalid_argument("height cannot be negative");
        }
        height = y;
    }
} // logic