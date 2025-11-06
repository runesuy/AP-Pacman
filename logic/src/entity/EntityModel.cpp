//
// Created by rune-suy on 11/6/25.
//

#include "entity/EntityModel.h"

namespace logic {

    void EntityModel::setSize(const Size &size) {
        this->size = size;
    }

    Size EntityModel::getSize() const {
        return size;
    }
}