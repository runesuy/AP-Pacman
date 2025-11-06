//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DRAWOBJECT_H
#define AP_PACMAN_DRAWOBJECT_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "IDrawable.h"
#include "world/WorldObject.h"

namespace renderer {

class DrawObject : public IDrawable {
    logic::Position position{0,0};
public:
    [[nodiscard]] const logic::Position& getPosition() const;

    void setPosition(const logic::Position &position);

    void draw(sf::RenderWindow &window) override;

    virtual std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) = 0;

    virtual std::vector<std::unique_ptr<sf::Sprite>> getSFSprites() = 0;

    virtual std::vector<std::unique_ptr<sf::Text>> getSFTexts() = 0;
};

} // renderer

#endif //AP_PACMAN_DRAWOBJECT_H
