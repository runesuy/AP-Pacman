//
// Created by runes on 4/11/2025.
//

#ifndef AP_PACMAN_IOBSERVABLE_H
#define AP_PACMAN_IOBSERVABLE_H


#include <memory>
#include <vector>
#include "IObserver.h"

namespace logic {

    /**
     * An class containing observing logic for integrating with the IObserver class.
     */
    class IObservable {
        std::vector<std::shared_ptr<IObserver<IObservable>>> _observers;

        /**
         * Call update in all observers
         */
        void updateObservers();
    };
}


#endif //AP_PACMAN_IOBSERVABLE_H
