//
// Created by rune-suy on 11/5/25.
//

#include <SFML/Graphics/Drawable.hpp>
#include "core/drawable/DrawObject.h"
#include "core/utils/Camera.h"

namespace renderer
{
    void DrawObject::draw(sf::RenderWindow& window)
    {
        for (auto& shape : getSFShapes(window))
        {
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            window.draw(*shape);
        }
        for (auto& shape : getSFSprites(window))
        {
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            auto s = *shape;
            window.draw(s);
        }
        for (auto& shape : getSFTexts(window))
        {
            shape->setPosition(shape->getPosition() + Camera::project(getPosition(), window));
            window.draw(*shape);
        }
    }

    const logic::Position& DrawObject::getPosition() const
    {
        return position;
    }

    void DrawObject::setPosition(const logic::Position& position)
    {
        this->position = position;
    }
} // renderer
