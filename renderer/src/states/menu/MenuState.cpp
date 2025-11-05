//
// Created by runes on 3/11/2025.
//

#include "../../../include/states/menu/MenuState.h"

namespace renderer {
    MenuState::MenuState(std::unique_ptr<IUpdateHandler> &&updateHandler, std::unique_ptr<IStateInputHandler> &&inputHandler,
                         std::unique_ptr<IDrawHandler> &&drawHandler) : DelegatingState(std::move(updateHandler), std::move(inputHandler),
                                                                                        std::move(drawHandler)) {

    }

} // renderer