//
// Created by runes on 4/11/2025.
//

#ifndef AP_PACMAN_OBSERVABLE_H
#define AP_PACMAN_OBSERVABLE_H


#include <memory>
#include <vector>
#include "IObserver.h"

namespace logic {

    /**
     * An class containing observing logic for integrating with the IObserver class.
     */
    class Observable {
        std::vector<std::shared_ptr<IObserver<Observable>>> _observers;

        /**
         * Call update in all observers
         */
        void updateObservers();

    public:
        /**
         * Add an observer to this observable
         * @param observer The observer to add
         */
        void addObserver(const std::shared_ptr<IObserver<Observable>>& observer);

        virtual ~Observable() = default;
    };
}


#endif //AP_PACMAN_OBSERVABLE_H
