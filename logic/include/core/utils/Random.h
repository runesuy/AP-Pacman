//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_RANDOM_H
#define AP_PACMAN_RANDOM_H

#include "memory"
#include <random>

namespace logic
{
    /**
     * A random class for all the game random logic.
     * Singleton class.
     */
    class Random
    {
        /**
         * Instance for singleton behaviour.
         */
        inline static std::shared_ptr<Random> _instance;

        /**
         * Private constructor for singleton behaviour.
         */
        Random();

        /**
         * The generator used for generating random numbers.
         */
        mutable std::mt19937 generator;

    public:
        ~Random() = default;

        //-- SINGLETON BEHAVIOUR--
        Random(Random&) = delete;

        Random(Random&&) noexcept = delete;

        void operator=(Random&) = delete;

        void operator=(Random&&) noexcept = delete;

        /**
         * Get the Random instance.
         * @return a pointer to the instance.
         */
        static std::shared_ptr<Random> getInstance();

        //-------

        /**
         * Get a random in in between min and max (including both) using an uniform distribution.
         * @param min The minimum value of the random int.
         * @param max The maximum value of the random int.
         * @return
         */
        int getIntInRange(int min, int max) const;
    };
}


#endif //AP_PACMAN_RANDOM_H
