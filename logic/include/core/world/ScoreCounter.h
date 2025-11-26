//
// Created by runes on 26/11/2025.
//

#ifndef AP_PACMAN_SCORECOUNTER_H
#define AP_PACMAN_SCORECOUNTER_H

#include "core/observer/Observable.h"

namespace logic {

    class ScoreCounter : public Observable<ScoreCounter> {
        /**
         * The current score.
         */
        int score = 0;
        float timeSinceLastCoin = 0.0f;
        float timeSinceLastDecay = 0.0f;

        int highScores[5] = {-1, -1, -1, -1, -1};

        inline static const int COIN_COLLECT_REWARD = 10;
        inline static const int GHOST_KILL_REWARD = 200;
        inline static const int SCORE_DECAY_RATE = 1; // per second
    public:
        /**
         * Change the score based on the provided event.
         * @param event
         */
        void processEvent(ObservableTypes::EventType event);

        /**
         * Load the highscores from file.
         * @param filename
         */
        void loadHighScores(const std::string &filename);

        /**
         * Load save the highscores to file.
         * @param filename
         */
        void saveHighScores(const std::string &filename) const;

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
