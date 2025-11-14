//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_SCOREVIEW_H
#define AP_PACMAN_SCOREVIEW_H

#include <SFML/Graphics/Text.hpp>
#include "core/observer/IObserver.h"
#include "core/world/Score.h"

namespace renderer {

class ScoreView : public logic::IObserver<logic::Score>, public sf::Drawable{
        sf::Text scoreText;
        sf::Font _font;
    public:
        void update(logic::Score &subject) override;

protected:
    void draw(RenderTarget &target, sf::RenderStates states) const override;
};

} // renderer

#endif //AP_PACMAN_SCOREVIEW_H
