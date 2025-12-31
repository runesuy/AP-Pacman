//
// Created by rune-suy on 11/6/25.
//

#include "core/entity/modular/ModularEntityView.h"

namespace renderer
{
    std::vector<std::unique_ptr<sf::Shape>> ModularEntityView::getSFShapes(sf::RenderWindow& window)
    {
        std::vector<std::unique_ptr<sf::Shape>> shapes;
        for (const auto& module : modules)
        {
            auto moduleShapes = module->getSFShapes(window);
            shapes.insert(shapes.end(),
                          std::make_move_iterator(moduleShapes.begin()),
                          std::make_move_iterator(moduleShapes.end()));
        }
        return std::move(shapes);
    }

    std::vector<std::shared_ptr<sf::Sprite>> ModularEntityView::getSFSprites(sf::RenderWindow& window)
    {
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        for (const auto& module : modules)
        {
            auto moduleSprites = module->getSFSprites(window);
            sprites.insert(sprites.end(),
                           std::make_move_iterator(moduleSprites.begin()),
                           std::make_move_iterator(moduleSprites.end()));
        }
        return std::move(sprites);
    }

    std::vector<std::unique_ptr<sf::Text>> ModularEntityView::getSFTexts(sf::RenderWindow& window)
    {
        std::vector<std::unique_ptr<sf::Text>> texts;
        for (const auto& module : modules)
        {
            auto moduleTexts = module->getSFTexts();
            texts.insert(texts.end(),
                         std::make_move_iterator(moduleTexts.begin()),
                         std::make_move_iterator(moduleTexts.end()));
        }
        return std::move(texts);
    }

    void ModularEntityView::addModule(std::shared_ptr<IEntityViewModule> module)
    {
        modules.push_back(std::move(module));
    }
} // renderer
