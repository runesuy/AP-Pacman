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
     * An observer class to track and manage the player's score.
     */
    class Score : public IObserver<PlayerModel> {

        ScoreCounter scoreCounter;
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
        void update(PlayerModel &subject, ObservableTypes::EventType event) override;

        [[nodiscard]] const LifeCounter &getLifeCounter() const;

        [[nodiscard]] LifeCounter &getLifeCounter();

        [[nodiscard]] const ScoreCounter &getScoreCounter() const;

        [[nodiscard]] ScoreCounter &getScoreCounter();
    };
}


#endif //AP_PACMAN_SCORE_H
