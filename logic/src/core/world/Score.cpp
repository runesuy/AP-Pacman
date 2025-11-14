//
// Created by runes on 3/11/2025.
//

#include "core/world/Score.h"

void logic::Score::update(logic::PlayerModel &subject) {

}

void logic::Score::update(PlayerModel &subject, const std::string &event) {
    if (event == "COIN_COLLECTED") {
        score += 10; // Example: increase score by 10 for each point collected
    }
}

void logic::Score::loadHighScores(const std::string &filename) {

}

void logic::Score::saveHighScores(const std::string &filename) const {

}

int logic::Score::getScore() const {
    return score;
}
