//
// Created by rune-suy on 11/12/25.
//

#include "game/entities/views/FruitView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"

namespace renderer
{
    void FruitView::update(logic::FruitModel& subject)
    {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        if (subject.isMarkedForRemoval())
        {
            markForRemoval();
        }
    }

    bool FruitView::isMarkedForRemoval()
    {
        return markedForRemoval;
    }

    FruitView::FruitView()
    {
        auto spriteModule = std::make_shared<SpriteModule>();
        spriteModule->setSize(getSize());
        spriteModule->setTexture(
            Game::getInstance()->getAppConfig().getRendererConfig().getTextureParser().getTexture("fruit"));
        addModule(spriteModule);
        addObserver(spriteModule);
        zIndex = -10;
    }

    void FruitView::setSize(const logic::Size& size)
    {
        EntityView::setSize(size);
        updateObservers();
    }

    void FruitView::markForRemoval()
    {
        markedForRemoval = true;
    }
} // renderer
