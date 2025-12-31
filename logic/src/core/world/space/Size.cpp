//
// Created by rune-suy on 11/5/25.
//

#include "core/world/space/Size.h"
#include "stdexcept"

namespace logic
{
    ICoordinate::CoordinateType Size::getX() const
    {
        return width;
    }

    void Size::setX(const CoordinateType x)
    {
        if (x < 0)
        {
            throw std::invalid_argument("width cannot be negative");
        }
        width = x;
    }

    Size::CoordinateType Size::getY() const
    {
        return height;
    }

    void Size::setY(const CoordinateType y)
    {
        if (y < 0)
        {
            throw std::invalid_argument("height cannot be negative");
        }
        height = y;
    }

    Size::Size(const CoordinateType x, const CoordinateType y)
    {
        if (x < 0)
        {
            throw std::invalid_argument("width cannot be negative");
        }
        width = x;
        if (y < 0)
        {
            throw std::invalid_argument("height cannot be negative");
        }
        height = y;
    }
} // logic
