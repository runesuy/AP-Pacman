//
// Created by rune-suy on 11/8/25.
//

#include "core/world/objects/SizedWorldObject.h"

namespace logic {
    void SizedWorldObject::setSize(const Size &size) {
        this->size = size;
    }

    Size SizedWorldObject::getSize() const {
        return size;
    }
} // logic