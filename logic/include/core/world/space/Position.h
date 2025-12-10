//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_POSITION_H
#define AP_PACMAN_POSITION_H


#include "ICoordinate.h"

namespace logic {
    /**
     * A position class for the game world.
     * x and y should always be between -1 and 1
     */
    class Position : public ICoordinate {
        CoordinateType x{};
        CoordinateType y{};
    public:
        /**
         * @param x horizontal coördinate, 0 being the center of the game world
         * @param y vertical coördinate, 0 being the center of the game world
         * @pre x is between -1 and 1
         * @pre y is between -1 and 1
         */
        Position(CoordinateType x, CoordinateType y);

        /**
         * Create a default position instance.
         */
        Position() = default;

        Position(Position &&) noexcept = default;

        Position(const Position &) = default;

        Position &operator=(Position &&) noexcept = default;

        Position &operator=(const Position &) = default;

        Position &operator+=(const Position &other);

        /**
         * Add up the corresponding x and y values.
         * @param other
         * @return
         */
        Position operator+(const Position &other) const;

        /**
         * Multiply x and y with a scalar.
         * @param scalar
         * @return
         */
        Position operator*(float scalar) const;

        bool operator==(const Position &other) const;

        /**
         * Check if this position is equal to another position within a certain epsilon.
         * @param other
         * @param eps
         * @return
         */
        [[nodiscard]] bool isEqualTo(const logic::Position &other, double eps) const;

        /**
         * @return the horizontal coördinate
         */
        [[nodiscard]] CoordinateType getX() const override;

        /**
         * Set the horizontal coördinate
         * @param x
         * @pre x must be between -1 and 1
         */
        void setX(CoordinateType x) override;

        /**
         * @return the vertical coördinate
         */
        [[nodiscard]] CoordinateType getY() const override;

        /**
         * Set the vertical coördinate
         * @param y
         * @pre y must be between -1 and 1
         */
        void setY(CoordinateType y) override;
    };
}


#endif //AP_PACMAN_POSITION_H
