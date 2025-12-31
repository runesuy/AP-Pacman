//
// Created by runes on 3/11/2025.
//

#include "core/world/space/Position.h"
#include <stdexcept>

namespace logic
{
    logic::Position::Position(CoordinateType x, CoordinateType y) : x(x), y(y)
    {
        if (x < -1 || x > 1)
        {
            throw std::invalid_argument("value of x should be between -1 and 1");
        }
        if (y < -1 || y > 1)
        {
            throw std::invalid_argument("value of y should be between -1 and 1");
        }
    }

    Position::CoordinateType logic::Position::getX() const
    {
        return x;
    }

    void logic::Position::setX(CoordinateType x)
    {
        if (x < -1 || x > 1)
        {
            throw std::invalid_argument("value of x should be between -1 and 1");
        }
        Position::x = x;
    }

    Position::CoordinateType logic::Position::getY() const
    {
        return y;
    }

    void logic::Position::setY(CoordinateType y)
    {
        if (y < -1 || y > 1)
        {
            throw std::invalid_argument("value of y should be between -1 and 1");
        }
        Position::y = y;
    }

    logic::Position& logic::Position::operator+=(const logic::Position& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    logic::Position logic::Position::operator+(const logic::Position& other) const
    {
        return {this->x + other.x, this->y + other.y};
    }

    logic::Position logic::Position::operator*(float scalar) const
    {
        return {this->x * scalar, this->y * scalar};
    }

    bool logic::Position::operator==(const logic::Position& other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    bool logic::Position::isEqualTo(const logic::Position& other, double eps) const
    {
        return std::abs(this->x - other.x) < eps && std::abs(this->y - other.y) < eps;
    }
}
