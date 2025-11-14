//
// Created by rune-suy on 11/14/25.
//

#include "core/world/ScoreView.h"

namespace renderer {
    void ScoreView::update(logic::Score &subject) {
        setString("Score: " + std::to_string(subject.getScore()));
    }

    ScoreView::ScoreView() {
        setString("Score: 0");
    }
} // renderer