//
// Created by runes on 4/11/2025.
//

#include "observer/Observable.h"

namespace logic {
    void logic::Observable::updateObservers() {
        for (auto &observer: _observers) {
            observer->update(std::shared_ptr<Observable>(this));
        }
    }

    void Observable::addObserver(const std::shared_ptr<IObserver<Observable>>& observer) {
        _observers.push_back(observer);
    }
}


