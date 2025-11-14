//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_SCORE_H
#define AP_PACMAN_SCORE_H
#include "core/observer/IObserver.h"
#include "game/entities/models/PlayerModel.h"

namespace logic {
    /**
     * An observer class to track and manage the player's score.
     */
    class Score : public IObserver<PlayerModel>, public Observable<Score>{
        int score=0;
        float timeSinceLastCoin=0.0f;
        float timeSinceLastDecay=0.0f;

        int highScores[5]={-1,-1,-1,-1,-1};

        const int COIN_COLLECT_REWARD = 10;
        const int SCORE_DECAY_RATE = 1; // per second
    public:
        void onTick();

        void update(PlayerModel &subject) override;

        void update(PlayerModel &subject, const std::string &event) override;

        void loadHighScores(const std::string& filename);

        void saveHighScores(const std::string& filename) const;

        [[nodiscard]] int getScore() const;

        void setScore(int score);
    };
}


#endif //AP_PACMAN_SCORE_H
