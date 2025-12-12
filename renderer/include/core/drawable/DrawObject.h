//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DRAWOBJECT_H
#define AP_PACMAN_DRAWOBJECT_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "core/drawable/IDrawable.h"
#include "core/world/objects/WorldObject.h"

namespace renderer {
    class DrawObject : public IDrawable {
        /**
         * Position of the draw object in the game world and on the screen.
         */
        logic::Position position{0, 0};

    public:
        /**
         * Get the position of the draw object.
         * @return
         */
        [[nodiscard]] const logic::Position &getPosition() const;

        /**
         * Set the position of the draw object.
         * @param position
         */
        virtual void setPosition(const logic::Position &position);

        /**
         * Draw the object onto the provided render window.
         * All shapes sprites and text will be drawn and scaled according to the position and size of the object, along with the DrawObject position.
         * @param window
         */
        void draw(sf::RenderWindow &window) override;

        /**
         * Get the SFML shapes representing the draw object.
         * @warning Use the logic::Position and logic::Size system when giving positions and sizes to the shapes.
         * @warning positions are relative to the DrawObject position.
         * @param window
         * @return
         */
        virtual std::vector<std::unique_ptr<sf::Shape> > getSFShapes(sf::RenderWindow &window) = 0;

        /**
         * Get the SFML sprites representing the draw object.
         * @warning Use the logic::Position and logic::Size system when giving positions and sizes
         * @warning positions are relative to the DrawObject position.
         * @return
         */
        virtual std::vector<std::shared_ptr<sf::Sprite> > getSFSprites(sf::RenderWindow &window) = 0;

        /**
         * Get the SFML texts representing the draw object.
         * @warning Use the logic::Position and logic::Size system when giving positions and sizes
         * @warning positions are relative to the DrawObject position.
         * @return
         */
        virtual std::vector<std::unique_ptr<sf::Text> > getSFTexts(sf::RenderWindow &window) = 0;
    };
} // renderer

#endif //AP_PACMAN_DRAWOBJECT_H
