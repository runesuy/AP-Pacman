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
    class Score : public IObserver<PlayerModel>{
        int score;

        int highScores[5]={-1,-1,-1,-1,-1};
    public:
        void update(PlayerModel &subject) override;

        void update(PlayerModel &subject, GameEventType eventType) override;

        void loadHighScores(const std::string& filename);

        void saveHighScores(const std::string& filename) const;
    };
}


#endif //AP_PACMAN_SCORE_H
