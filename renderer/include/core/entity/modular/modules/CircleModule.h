//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_RECTANGLEMODULE_H
#define AP_PACMAN_RECTANGLEMODULE_H
#include "core/entity/modular/IEntityViewModule.h"
#include "core/world/space/Size.h"
#include "core/observer/IObserver.h"
#include "core/entity/modular/ModularEntityView.h"

namespace renderer {

class CircleModule : public IEntityViewModule {
    public:
        CircleModule()=default;

        logic::Size size={0.1,0.1};

        sf::Color fillColor = sf::Color::Red;

    public:
        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) const override;

        [[nodiscard]] std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow &window) const override;

        [[nodiscard]] std::vector<std::unique_ptr<sf::Text>> getSFTexts() const override;

        [[nodiscard]] const logic::Size &getSize() const;

        void setSize(const logic::Size &size);

        void update(ModularEntityView &subject) override;

        void setFillColor(const sf::Color &color);

    };

} // renderer

#endif //AP_PACMAN_RECTANGLEMODULE_H
