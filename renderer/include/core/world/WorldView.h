//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_WORLDVIEW_H
#define AP_PACMAN_WORLDVIEW_H
#include "core/observer/IObserver.h"
#include "core/world/World.h"
#include "IWorldObjectView.h"
#include "game/ScoreView.h"
#include "game/LivesView.h"

namespace renderer
{
    class WorldView : public logic::IObserver<logic::World>
    {
        std::vector<std::shared_ptr<IWorldObjectView>> objectViews;

        /**
     * Clean up views that are no longer needed.
     * Removes all views that are not associated with any world object.
     */
        void _cleanUpViews();

        std::shared_ptr<ScoreView> scoreView = std::make_shared<ScoreView>();
        std::shared_ptr<LivesView> livesView = std::make_shared<LivesView>();

    public:
        void update(logic::World& subject) override;

        void draw(sf::RenderWindow& window);

        void addObjectView(const std::shared_ptr<IWorldObjectView>& objectView);
    };
} // renderer

#endif //AP_PACMAN_WORLDVIEW_H
