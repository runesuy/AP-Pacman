//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/views/PlayerView.h"

namespace renderer {
    void PlayerView::update(logic::PlayerModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

} // renderer