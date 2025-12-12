//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_IENTITYVIEWMODULE_H
#define AP_PACMAN_IENTITYVIEWMODULE_H
#include <vector>
#include <memory>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "core/observer/IObserver.h"

namespace renderer {
    class ModularEntityView;

    /**
     * Module interface for ModularEntityView.
     */
    class IEntityViewModule : public logic::IObserver<ModularEntityView> {
    public:
        virtual std::vector<std::unique_ptr<sf::Shape> > getSFShapes(sf::RenderWindow &window) const = 0;

        [[nodiscard]] virtual std::vector<std::shared_ptr<sf::Sprite> > getSFSprites(sf::RenderWindow &window) const =
        0;

        [[nodiscard]] virtual std::vector<std::unique_ptr<sf::Text> > getSFTexts() const = 0;
    };
} // renderer

#endif //AP_PACMAN_IENTITYVIEWMODULE_H
