//
// Created by runes on 25/11/2025.
//

#include "game/LivesView.h"

void renderer::LivesView::update(logic::LifeCounter &subject) {
    livesLeft = subject.getLivesLeft();
    setString(preFix + std::to_string(livesLeft));
}

renderer::LivesView::LivesView() {
    setString(preFix + std::to_string(livesLeft));
}
