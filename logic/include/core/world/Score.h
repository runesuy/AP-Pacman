//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_SCORE_H
#define AP_PACMAN_SCORE_H

#include "core/observer/IObserver.h"
#include "game/entities/models/PlayerModel.h"
#include "LifeCounter.h"

namespace logic {
    /**
     * An observer class to track and manage the player's score.
     */
    class Score : public IObserver<PlayerModel>, public Observable<Score> {
        int score = 0;
        float timeSinceLastCoin = 0.0f;
        float timeSinceLastDecay = 0.0f;

        int highScores[5] = {-1, -1, -1, -1, -1};

        const int COIN_COLLECT_REWARD = 10;
        const int GHOST_KILL_REWARD = 200;
        const int SCORE_DECAY_RATE = 1; // per second

        LifeCounter lifeCounter;
    public:
        /**
         * Called on each tick.
         */
        void onTick();

        /**
         * Update score based on player change.
         * @param subject
         */
        void update(PlayerModel &subject) override;

        /**
         * Update score based on player event.
         * @param subject
         */
        void update(PlayerModel &subject, Observable::EventType event) override;

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

        [[nodiscard]] const LifeCounter &getLifeCounter() const;

        [[nodiscard]] LifeCounter &getLifeCounter();
    };
}


#endif //AP_PACMAN_SCORE_H
