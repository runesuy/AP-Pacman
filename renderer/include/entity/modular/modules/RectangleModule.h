//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_RECTANGLEMODULE_H
#define AP_PACMAN_RECTANGLEMODULE_H
#include "entity/modular/IEntityViewModule.h"
#include "world/Size.h"
#include "observer/IObserver.h"
#include "entity/modular/ModularEntityView.h"

namespace renderer {

class RectangleModule : public IEntityViewModule {
    public:
        RectangleModule()=default;

        logic::Size size={0.1,0.1};

        sf::Color fillColor = sf::Color::Red;

    public:
        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) const override;

        [[nodiscard]] std::vector<std::shared_ptr<sf::Sprite>> getSFSprites() const override;

        [[nodiscard]] std::vector<std::unique_ptr<sf::Text>> getSFTexts() const override;

        [[nodiscard]] const logic::Size &getSize() const;

        void setSize(const logic::Size &size);

        void update(std::shared_ptr<ModularEntityView> subject) override;

        void setFillColor(const sf::Color &color);

    };

} // renderer

#endif //AP_PACMAN_RECTANGLEMODULE_H
