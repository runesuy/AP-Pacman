//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERVIEW_H
#define AP_PACMAN_PLAYERVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/PlayerModel.h"

namespace renderer
{
    class PlayerView : public ModularEntityView, public logic::IObserver<logic::PlayerModel>
    {
        inline static const std::map<std::string, std::vector<std::string>> animations{
            {
                "move-right",
                {"player-right_0", "player-right_1", "player-right_2"},
            },
            {
                "move-left",
                {"player-left_0", "player-left_1", "player-left_2"}
            },
            {
                "move-up",
                {"player-up_0", "player-up_1", "player-up_2"}
            },
            {
                "move-down",
                {"player-down_0", "player-down_1", "player-down_2"}
            },
            {
                "none",
                {"player-none"}
            }
        };

        void _updateAnimation();

        logic::Direction direction;

    public:
        PlayerView();

        void update(logic::PlayerModel& subject) override;

        void setSize(const logic::Size& size) override;

        bool isMarkedForRemoval() override;

        void setDirection(logic::Direction direction);
    };
} // renderer

#endif //AP_PACMAN_PLAYERVIEW_H
