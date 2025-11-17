//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_SIZE_H
#define AP_PACMAN_SIZE_H

#include "ICoordinate.h"

namespace logic {

    /**
     * A size class representing width and height.
     * Size width and height must always be non-negative.
     */
    class Size : public ICoordinate {
        CoordinateType width;
        CoordinateType height;
    public:
        Size(CoordinateType x, CoordinateType y);
        Size(Size&&) noexcept = default;
        Size(const Size&) = default;
        Size& operator=(Size&&) noexcept = default;
        Size& operator=(const Size&) = default;

        /**
         * @return The width
         */
        [[nodiscard]] CoordinateType getX() const override;

        /**
         * Set the width
         * @param x width (>=0)
         */
        void setX(CoordinateType x) override;

        /**
         * @return The height
         */
        [[nodiscard]] CoordinateType getY() const override;

        /**
         * Set the height
         * @param y height (>=0)
         */
        void setY(CoordinateType y) override;
    };

} // logic

#endif //AP_PACMAN_SIZE_H
