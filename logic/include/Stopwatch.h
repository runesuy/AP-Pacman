//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_STOPWATCH_H
#define AP_PACMAN_STOPWATCH_H
#include "chrono"

namespace logic {
    using namespace std::chrono;

    /**
     * Calculates and holds the time in seconds between the last two ticks.
     */
    class Stopwatch {
        /**
         * Holds the previous tick timepoint.
         */
        time_point<high_resolution_clock, high_resolution_clock ::duration> _previous;

        /**
         * True if this is the first time tick is called.
         */
        bool _firstTick = true;

        /**
         * The time between the last tick and the one before that. In seconds.
         */
        float deltaTime=0;

    public:

        /**
         *  Update the deltaTime
         *  Sets deltaTime to the gap in seconds between this and the previous tick.
         *  Returns zero first time tick() is called.
         */
        void tick() noexcept;

        /**
         * @return The time between the previous two ticks in seconds. 0 if tick has only been called once.
         */
        [[nodiscard]] float getDeltaTime() const noexcept;
    };
}


#endif //AP_PACMAN_STOPWATCH_H
