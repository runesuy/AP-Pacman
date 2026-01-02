//
// Created by runes on 26/11/2025.
//

#include "core/world/ScoreCounter.h"
#include "game/entities/ObserverEvents.h"
#include "core/utils/Stopwatch.h"

namespace logic
{
    void ScoreCounter::processEvent(ObservableTypes::EventType event)
    {
        if (event == ObserverEvents::PLAYER_COIN_COLLECTED)
        {
            setScore(score + static_cast<int>(COIN_COLLECT_REWARD * (1 / (timeSinceLastCoin == 0
                                                                              ? 1
                                                                              : 1 +
                                                                              timeSinceLastCoin *
                                                                              COIN_COLLECT_REWARD))));
            // Example: increase score by 10 for each point collected
            timeSinceLastCoin = 0;
        }
        if (event == ObserverEvents::PLAYER_GHOST_KILLED)
        {
            setScore(score + GHOST_KILL_REWARD);
        }
        if (event == ObserverEvents::PLAYER_FRUIT_COLLECTED)
        {
            setScore(score + FRUIT_COLLECT_REWARD);
        }

        updateObservers();
    }

    int ScoreCounter::getScore() const
    {
        return score;
    }

    void ScoreCounter::setScore(int score)
    {
        ScoreCounter::score = score;
        updateObservers();
    }

    void ScoreCounter::onTick()
    {
        timeSinceLastCoin = Stopwatch::getInstance()->getDeltaTime();
        timeSinceLastDecay += Stopwatch::getInstance()->getDeltaTime();
        while (timeSinceLastDecay >= 1.0f)
        {
            setScore(std::max(0, score - SCORE_DECAY_RATE));
            timeSinceLastDecay -= 1.0f;
        }
    }

    ScoreCounter::ScoreCounter()
    {
        highScores = highScoreParser->getHighScores(highScoreFilePath);
    }

    void ScoreCounter::loadHighScores()
    {
        highScores = highScoreParser->getHighScores(highScoreFilePath);
    }

    void ScoreCounter::saveHighScores()
    {
        if (score > highScores.at(highScores.size() - 1))
        {
            highScores.push_back(score);
            std::sort(highScores.begin(), highScores.end(), std::greater<>());
            highScores.pop_back();
        }
        highScoreParser->writeHighScores(highScores, highScoreFilePath);
    }
} // logic
