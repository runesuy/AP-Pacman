//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_RANDOM_H
#define AP_PACMAN_RANDOM_H
#include "memory"

namespace logic {
    /**
     * A random class for all the game random logic.
     * Singleton class.
     */
    class Random {
        static std::shared_ptr<Random> _instance;
        Random()=default;

    public:
        ~Random()=default;
        Random(Random&) = delete;
        Random(Random&&) noexcept = delete;
        void operator=(Random&) = delete;
        void operator=(Random&&) noexcept = delete;

        /**
         * Get the Random instance.
         * @return a pointer to the instance.
         */
        static std::shared_ptr<Random> getInstance();
    };
}


#endif //AP_PACMAN_RANDOM_H
