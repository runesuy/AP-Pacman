//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DRAWCOLLECTION_H
#define AP_PACMAN_DRAWCOLLECTION_H
#include <vector>
#include <memory>
#include "IDrawable.h"

namespace renderer {

    /**
     * Collection class to manage multiple drawable objects.
     */
    class DrawCollection {
        std::vector<std::shared_ptr<IDrawable>> drawables;

    public:
        DrawCollection() = default;

        /**
         * Add a drawable object to the collection.
         * @param drawable
         */
        void addDrawable(const std::shared_ptr<IDrawable>& drawable);

        /**
         * Get the list of drawable objects in the collection.
         * @return
         */
        [[nodiscard]] const std::vector<std::shared_ptr<IDrawable>>& getDrawables() const;

        /**
         * Draw all drawable objects onto the provided render window.
         * @param window
         */
        void draw(sf::RenderWindow& window);
    };

} // renderer

#endif //AP_PACMAN_DRAWCOLLECTION_H
