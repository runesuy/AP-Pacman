//
// Created by rune-suy on 11/14/25.
//

#include "game/ScoreView.h"

namespace renderer {
    void ScoreView::update(logic::Score &subject) {
        scoreText.setString(std::to_string(subject.getScore()));
    }

    void ScoreView::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    }
} // renderer