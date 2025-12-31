//
// Created by runes on 21/11/2025.
//

#ifndef AP_PACMAN_LIFECOUNTER_H
#define AP_PACMAN_LIFECOUNTER_H

#include "core/observer/Observable.h"

namespace logic
{
    /**
     * Keeps track of the amount of lives of the player.
     * @see Score
     */
    class LifeCounter : public Observable<LifeCounter>
    {
        inline static const unsigned int lifeStart = 3;
        unsigned int livesLeft = lifeStart;

    public:
        using LivesAmountType = unsigned int;

        LifeCounter() = default;

        /**
         * Set the amount of lives left.
         * updates the observers.
         * @param livesLeft
         */
        void setLivesLeft(LivesAmountType livesLeft);

        /**
         * @return the amount of lives the counter starts on on creation.
         */
        static LivesAmountType getLifeStart();

        /**
         * @return The amount of lives the player has left.
         */
        [[nodiscard]] LivesAmountType getLivesLeft() const;

        /**
         * Sets livesLeft to min(lifeStart, livesLeft + amount)
         * @param amount
         */
        void addLives(LivesAmountType amount);

        /**
         * Removes amount from lives. Lives will not go negative.
         * @param amount
         */
        void removeLives(LivesAmountType amount);

        /**
         * Change the amount of lives based on the provided event.
         * @param event
         */
        void processEvent(ObservableTypes::EventType event);
    };
} // logic

#endif //AP_PACMAN_LIFECOUNTER_H
