//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_SIZE_H
#define AP_PACMAN_SIZE_H

#include "ICoordinate.h"

namespace logic {

    class Size : public ICoordinate {
        float width;
        float height;
    public:
        Size(float x, float y);
        Size(Size&&) noexcept = default;
        Size(const Size&) = default;
        Size& operator=(Size&&) noexcept = default;
        Size& operator=(const Size&) = default;

        [[nodiscard]] float getX() const override;

        void setX(float x) override;

        [[nodiscard]] float getY() const override;

        void setY(float y) override;
    };

} // logic

#endif //AP_PACMAN_SIZE_H
