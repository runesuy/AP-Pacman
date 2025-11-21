//
// Created by runes on 21/11/2025.
//

#ifndef AP_PACMAN_LIFECOUNTER_H
#define AP_PACMAN_LIFECOUNTER_H

#include "game/entities/models/PlayerModel.h"

namespace logic {

    class LifeCounter : public IObserver<PlayerModel>, public Observable<LifeCounter> {
        inline static const int lifeStart = 3;
        unsigned int livesLeft = lifeStart;
    public:
        void setLivesLeft(unsigned int livesLeft);

    public:
        LifeCounter()=default;
        static unsigned int getLifeStart();

        [[nodiscard]] unsigned int getLivesLeft() const;

        /**
         * Sets livesLeft to min(lifeStart, livesLeft + amount)
         * @param amount
         */
        void addLives(unsigned int amount);

        /**
         * Removes amount from lives. Lives will not go negative.
         * @param amount
         */
        void removeLives(unsigned int amount);

        void update(PlayerModel &subject) override;

        void update(PlayerModel &subject, const std::string &event) override;
    };




} // logic

#endif //AP_PACMAN_LIFECOUNTER_H
