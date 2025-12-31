//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_TIMER_H
#define AP_PACMAN_TIMER_H

#include "Stopwatch.h"

namespace logic
{
    /**
     * Timer class used for timers counting down from a startTime to 0.
     * Can be added to Stopwatch to simulate on each tick.
     */
    class Stopwatch::Timer
    {
        TimeType timeLeft;
        const TimeType totalTime;
        bool running=false;

        void tick();

        friend class Stopwatch;

    public:
        explicit Timer(TimeType totalTime);

        void start();

        void stop();

        [[nodiscard]] bool isCompleted() const;

        [[nodiscard]] bool isRunning() const;
    };
} // logic

#endif //AP_PACMAN_TIMER_H
