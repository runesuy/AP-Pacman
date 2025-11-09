//
// Created by runes on 3/11/2025.
//

#include "core/world/Score.h"

void logic::Score::update(logic::PlayerModel &subject) {

}

void logic::Score::update(logic::PlayerModel &subject, logic::GameEventType eventType) {

    switch (eventType) {
        case COIN_COLLECTED:{
            score += 10;
            break;
        }
    }
}

void logic::Score::loadHighScores(const std::string &filename) {

}

void logic::Score::saveHighScores(const std::string &filename) const {

}
