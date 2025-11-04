//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_CAMERA_H
#define AP_PACMAN_CAMERA_H

#include <tuple>
#include <SFML/Graphics/RenderWindow.hpp>
#include "world/Position.h"

namespace renderer {
    class Camera {
    public:
        /**
         * Projects the logical position to the screen position.
         * @param posX Logical X position between -1 and 1;
         * @param window The render window to project to.
         * @return The screen X position in pixels.
         */
        static int projectX(float posX, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen X position in pixels.
         */
        static int projectX(const logic::Position& position, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param posX Logical Y position between -1 and 1;
         * @param window The render window to project to.
         * @return The screen Y position in pixels.
         */
        static int projectY(float posY, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen Y position in pixels.
         */
        static int projectY(const logic::Position& position, const sf::RenderWindow& window);

        /**
         * Projects the logical position to the screen position.
         * @param position Logical position;
         * @param window The render window to project to.
         * @return The screen position in pixels.
         */
        static std::tuple<int, int> project(const logic::Position& position, const sf::RenderWindow& window);
    };
}


#endif //AP_PACMAN_CAMERA_H
