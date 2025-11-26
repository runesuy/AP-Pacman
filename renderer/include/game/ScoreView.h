//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_SCOREVIEW_H
#define AP_PACMAN_SCOREVIEW_H

#include "../../../../../../SFML-2.6.2/include/SFML/Graphics/Text.hpp"
#include "core/observer/IObserver.h"
#include "core/world/Score.h"
#include "../core/drawable/ui/Label.h"

namespace renderer {

class ScoreView : public logic::IObserver<logic::ScoreCounter>, public Label{
    public:
        ScoreView();
        void update(logic::ScoreCounter &subject) override;

};

} // renderer

#endif //AP_PACMAN_SCOREVIEW_H
