//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_SCORE_H
#define AP_PACMAN_SCORE_H

#include "core/observer/IObserver.h"
#include "game/entities/models/PlayerModel.h"
#include "LifeCounter.h"
#include "ScoreCounter.h"

namespace logic {
    /**
     * An observer class to track and manage the player's score and lives.
     */
    class Score : public IObserver<PlayerModel> {

        ScoreCounter scoreCounter;
        LifeCounter lifeCounter;
        float difficultyMultiplier=1;
        static constexpr float DIFFICULTY_INCREASE = 0.1;
    public:
        /**
         * Called on each tick.
         * Changes the score based on the deltaTime provided by StopWatch
         */
        void onTick();

        /**
         * Update score and lives based on player change.
         * @param subject
         */
        void update(PlayerModel &subject) override;

        /**
         * Update score and lives based on player event.
         * @param subject
         */
        void update(PlayerModel &subject, ObservableTypes::EventType event) override;

        /**
         * @return The LifeCounter instance that handles the player lives.
         */
        [[nodiscard]] const LifeCounter &getLifeCounter() const;

        /**
         * @return The LifeCounter instance that handles the player lives.
         */
        [[nodiscard]] LifeCounter &getLifeCounter();

        /**
         * @return The ScoreCounter instance that handles the player score.
         */
        [[nodiscard]] const ScoreCounter &getScoreCounter() const;

        /**
         * @return The ScoreCounter instance that handles the player score.
         */
        [[nodiscard]] ScoreCounter &getScoreCounter();

        [[nodiscard]] float getDifficultyMultiplier() const;

        void increaseDifficultyMultiplier();
    };
}


#endif //AP_PACMAN_SCORE_H
