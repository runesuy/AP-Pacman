//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_POSITION_H
#define AP_PACMAN_POSITION_H


namespace logic {
    /**
     * A position class for the game world.
     * x and y should always be between -1 and 1
     */
    class Position {
        float x;
        float y;
    public:
        /**
         * @param x horizontal coördinate, 0 being the center of the game world
         * @param y vertical coördinate, 0 being the center of the game world
         * @pre x is between -1 and 1
         * @pre y is between -1 and 1
         */
        Position(float x, float y);
        Position(Position&&) noexcept = default;
        Position(Position&) = default;
        Position& operator=(Position&&) noexcept = default;
        Position& operator=(const Position&) = default;

        /**
         * @return the horizontal coördinate
         */
        [[nodiscard]] float getX() const;

        /**
         * Set the horizontal coördinate
         * @param x
         * @pre x must be between -1 and 1
         */
        void setX(float x);

        /**
         * @return the vertical coördinate
         */
        [[nodiscard]] float getY() const;

        /**
         * Set the vertical coördinate
         * @param y
         * @pre y must be between -1 and 1
         */
        void setY(float y);
    };
}


#endif //AP_PACMAN_POSITION_H
