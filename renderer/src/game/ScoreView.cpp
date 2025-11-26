//
// Created by rune-suy on 11/14/25.
//

#include "game/ScoreView.h"

namespace renderer {
    void ScoreView::update(logic::Score &subject) {
        setString("SCORE: " + std::to_string(subject.getScore()));
    }

    ScoreView::ScoreView() {
        setString("SCORE: 0");
    }
} // renderer