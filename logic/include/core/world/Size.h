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
        float width;
        float height;
    public:
        Size(float x, float y);
        Size(Size&&) noexcept = default;
        Size(const Size&) = default;
        Size& operator=(Size&&) noexcept = default;
        Size& operator=(const Size&) = default;

        /**
         * @return The width
         */
        [[nodiscard]] float getX() const override;

        /**
         * Set the width
         * @param x width (>=0)
         */
        void setX(float x) override;

        /**
         * @return The height
         */
        [[nodiscard]] float getY() const override;

        /**
         * Set the height
         * @param y height (>=0)
         */
        void setY(float y) override;
    };

} // logic

#endif //AP_PACMAN_SIZE_H
