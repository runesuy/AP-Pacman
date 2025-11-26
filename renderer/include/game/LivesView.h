//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_LIVESVIEW_H
#define AP_PACMAN_LIVESVIEW_H

#include "../../../../../../SFML-2.6.2/include/SFML/Graphics/Text.hpp"
#include "core/observer/IObserver.h"
#include "core/world/Score.h"
#include "../core/drawable/ui/Label.h"

namespace renderer {

class LivesView : public logic::IObserver<logic::LifeCounter>, public Label{
    const std::string preFix = "# LIVES REMAINING: ";
    logic::LifeCounter::LivesAmountType livesLeft;
    public:
        LivesView();

        void update(logic::LifeCounter &subject) override;

};

} // renderer

#endif //AP_PACMAN_LIVESVIEW_H
