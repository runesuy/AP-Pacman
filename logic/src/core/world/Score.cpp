//
// Created by runes on 3/11/2025.
//

#include "core/world/Score.h"
#include "core/utils/Stopwatch.h"
#include "game/entities/ObserverEvents.h"

void logic::Score::update(logic::PlayerModel &subject) {

}

void logic::Score::update(PlayerModel &subject, Observable::EventType event) {
    if (event == ObserverEvent::PLAYER_COIN_COLLECTED) {
        score += static_cast<int>(COIN_COLLECT_REWARD*(1/(timeSinceLastCoin==0 ? 1 : 1+timeSinceLastCoin*COIN_COLLECT_REWARD))); // Example: increase score by 10 for each point collected
        timeSinceLastCoin = 0;
    }
    if (event == ObserverEvent::PLAYER_GHOST_KILLED) {
        score += GHOST_KILL_REWARD;
    }
    if (event == ObserverEvent::PLAYER_KILLED) {
        lifeCounter.removeLives(1);
    }
    updateObservers();
}

void logic::Score::loadHighScores(const std::string &filename) {

}

void logic::Score::saveHighScores(const std::string &filename) const {

}

int logic::Score::getScore() const {
    return score;
}

void logic::Score::onTick() {
    timeSinceLastCoin = Stopwatch::getInstance()->getDeltaTime();
    timeSinceLastDecay += Stopwatch::getInstance()->getDeltaTime();
    while (timeSinceLastDecay >= 1.0f) {
        setScore(std::max(0, score - SCORE_DECAY_RATE));
        timeSinceLastDecay -= 1.0f;
    }
}

void logic::Score::setScore(int score) {
    Score::score = score;
    updateObservers();
}

const logic::LifeCounter &logic::Score::getLifeCounter() const {
    return lifeCounter;
}

 logic::LifeCounter &logic::Score::getLifeCounter() {
    return lifeCounter;
}
