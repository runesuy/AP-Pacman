//
// Created by runes on 26/11/2025.
//

#include "core/world/ScoreCounter.h"
#include "game/entities/ObserverEvents.h"
#include "core/utils/Stopwatch.h"

namespace logic {
    void ScoreCounter::processEvent(ObservableTypes::EventType event) {
        if (event == ObserverEvent::PLAYER_COIN_COLLECTED) {
            score += static_cast<int>(COIN_COLLECT_REWARD*(1/(timeSinceLastCoin==0 ? 1 : 1+timeSinceLastCoin*COIN_COLLECT_REWARD))); // Example: increase score by 10 for each point collected
            timeSinceLastCoin = 0;
        }
        if (event == ObserverEvent::PLAYER_GHOST_KILLED) {
            score += GHOST_KILL_REWARD;
        }

        updateObservers();
    }

    void ScoreCounter::loadHighScores(const std::string &filename) {

    }

    void ScoreCounter::saveHighScores(const std::string &filename) const {

    }

    int ScoreCounter::getScore() const {
        return score;
    }

    void ScoreCounter::setScore(int score) {
        ScoreCounter::score = score;
        updateObservers();
    }

    void ScoreCounter::onTick() {
        timeSinceLastCoin = Stopwatch::getInstance()->getDeltaTime();
        timeSinceLastDecay += Stopwatch::getInstance()->getDeltaTime();
        while (timeSinceLastDecay >= 1.0f) {
            setScore(std::max(0, score - SCORE_DECAY_RATE));
            timeSinceLastDecay -= 1.0f;
        }
    }
} // logic