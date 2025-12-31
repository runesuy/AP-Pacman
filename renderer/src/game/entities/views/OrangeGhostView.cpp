//
// Created by rune-suy on 11/13/25.
//

#include "game/entities/views/OrangeGhostView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer
{
    OrangeGhostView::OrangeGhostView() : GhostView(animations)
    {
    }
} // renderer
