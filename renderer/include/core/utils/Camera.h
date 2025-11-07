//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_CAMERA_H
#define AP_PACMAN_CAMERA_H

#include <tuple>
#include <SFML/Graphics/RenderWindow.hpp>
#include "world/Position.h"
#include "SFML/Graphics.hpp"
#include "world/Size.h"

namespace renderer {

    /**
     * Utility class for projecting logical game coordinates to screen coordinates.
     * Provides static methods to convert logical positions and sizes to pixel values
     * based on the dimensions of the render window.
     */
    class Camera {
    public:
        /**
         * Projects the logical position to the screen position.
         * @param posX Logical X position between -1 and 1;
         * @param window The render window to project to.
         * @return The screen X position in pixels.
         */
        static float projectX(float posX, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen X position in pixels.
         */
        static float projectX(const logic::Position& position, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param posX Logical Y position between -1 and 1;
         * @param window The render window to project to.
         * @return The screen Y position in pixels.
         */
        static float projectY(float posY, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen Y position in pixels.
         */
        static float projectY(const logic::Position& position, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen position in pixels.
         */
        static sf::Vector2<float> project(const logic::Position& position, const sf::RenderWindow& window);

        /**
         * Projects the size position to the screen size.
         * @param size Logical size;
         * @param window The render window to project to.
         * @return The screen size in pixels.
         */
        static sf::Vector2<float> project(const logic::Size& size, const sf::RenderWindow& window);


        /**
         * Projects the logical size to the screen size.
         * @param sizeX Logical X size between -1 and 1;
         * @param window The render window to project to.
         * @return The screen X size in pixels.
         */
        static float sizeX(float sizeX, const sf::RenderWindow& window);

        /**
         * Projects the logical size to the screen size.
         * @param sizeX Logical Y size between -1 and 1;
         * @param window The render window to project to.
         * @return The screen Y size in pixels.
         */
        static float sizeY(float sizeY, const sf::RenderWindow& window);
    };
}


#endif //AP_PACMAN_CAMERA_H
