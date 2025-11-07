//
// Created by rune-suy on 11/6/25.
//

#include "core/entity/EntityModel.h"

namespace logic {

    void EntityModel::setSize(const Size &size) {
        this->size = size;
    }

    Size EntityModel::getSize() const {
        return size;
    }

    void EntityModel::setController(const std::shared_ptr<IEntityController> &controller) {
        EntityModel::controller = controller;
    }

    void EntityModel::update() {
        if (controller) {
            controller->update(shared_from_this());
        }
    }
}