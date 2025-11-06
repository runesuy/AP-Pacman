//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_WALLVIEW_H
#define AP_PACMAN_WALLVIEW_H

#include "EntityView.h"
#include "entity/WallModel.h"

namespace renderer {

    /**
     * View class representing the visual aspect of a wall entity in the game.
     * Inherits from EntityView and implements the observer pattern to update its state based on the WallModel.
     */
    class WallView : public EntityView, public logic::IObserver<logic::WallModel>{
    public:
        WallView();

        void update(std::shared_ptr<logic::WallModel> subject) override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) override;

        std::vector<std::unique_ptr<sf::Sprite>> getSFSprites() override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts() override;
    };

} // renderer

#endif //AP_PACMAN_WALLVIEW_H
