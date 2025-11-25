//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_RANDOM_H
#define AP_PACMAN_RANDOM_H
#include "memory"
#include <random>

namespace logic {
    /**
     * A random class for all the game random logic.
     * Singleton class.
     */
    class Random {
        inline static std::shared_ptr<Random> _instance;
        std::mt19937 generator;
        Random();

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

        int getIntInRange(int min, int max);
    };
}


#endif //AP_PACMAN_RANDOM_H
