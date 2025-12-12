//
// Created by runes on 26/11/2025.
//

#ifndef AP_PACMAN_SCORECOUNTER_H
#define AP_PACMAN_SCORECOUNTER_H

#include "core/observer/Observable.h"
#include "core/parsers/IHighScoreParser.h"
#include "core/parsers/TXTHighScoreParser.h"

namespace logic {

    class ScoreCounter : public Observable<ScoreCounter> {
        /**
         * The current score.
         */
        int score = 0;
        float timeSinceLastCoin = 0.0f;
        float timeSinceLastDecay = 0.0f;

        using HighScoresList = std::vector<int>;
        HighScoresList highScores = {-1, -1, -1, -1, -1};

        static constexpr int COIN_COLLECT_REWARD = 10;
        static constexpr int FRUIT_COLLECT_REWARD = 100;
        static constexpr int GHOST_KILL_REWARD = 200;
        static constexpr int SCORE_DECAY_RATE = 1; // per second

        const std::unique_ptr<IHighScoreParser> highScoreParser = std::make_unique<TXTHighScoreParser>();
        inline static const std::string highScoreFilePath = "resources/highscores.txt";
    public:
        ScoreCounter();
        /**
         * Change the score based on the provided event.
         * @param event
         */
        void processEvent(ObservableTypes::EventType event);

        /**
         * Load the highscores from file.
         * @param filename
         */
        void loadHighScores();

        /**
         * Load save the highscores to file.
         * @param filename
         */
        void saveHighScores();

        /**
         * @return The current score.
         */
        [[nodiscard]] int getScore() const;

        /**
         * Set the score;
         * @param score
         */
        void setScore(int score);

        /**
         * Decreases the score based on SCORE_DECAY_RATE and DeltaTime provided by StopWatch on each tick.
         */
        void onTick();
    };

} // logic

#endif //AP_PACMAN_SCORECOUNTER_H
