//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ICOORDINATE_H
#define AP_PACMAN_ICOORDINATE_H

namespace logic {

    /**
     * Interface representing a 2D coordinate with x and y values.
     */
    class ICoordinate {
    public:
        /**
         * Type used in the 2D coördinate system.
         */
        using CoordinateType = double;

        /**
         * @return the horizontal coördinate
         */
        [[nodiscard]] virtual CoordinateType getX() const = 0;

        /**
         * Set the horizontal coördinate
         * @param x
         * @pre x must be between -1 and 1
         */
        virtual void setX(CoordinateType x) = 0;

        /**
         * @return the vertical coördinate
         */
        [[nodiscard]] virtual CoordinateType getY() const = 0;

        /**
         * Set the vertical coördinate
         * @param y
         * @pre y must be between -1 and 1
         */
        virtual void setY(CoordinateType y) = 0;
    };

} // logic

#endif //AP_PACMAN_ICOORDINATE_H
