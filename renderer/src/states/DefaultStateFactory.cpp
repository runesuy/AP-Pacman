//
// Created by rune-suy on 11/4/25.
//

#include "../../include/states/DefaultStateFactory.h"
#include "../../include/states/menu/MenuDrawHandler.h"
#include "../../include/states/menu/MenuUpdateHandler.h"
#include "../../include/states/menu/MenuInputHandler.h"

namespace renderer {
    std::unique_ptr<MenuState> DefaultStateFactory::createMenuState() {
        auto updateHandler = std::make_unique<MenuUpdateHandler>();
        auto inputHandler =  std::make_unique<MenuInputHandler>();
        auto drawHandler =  std::make_unique<MenuDrawHandler>();
        return std::make_unique<MenuState>(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler));
    }
} // renderer