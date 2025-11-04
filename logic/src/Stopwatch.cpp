//
// Created by runes on 3/11/2025.
//

#include "Stopwatch.h"

using namespace std::chrono;

void logic::Stopwatch::tick() noexcept{
    time_point<high_resolution_clock, high_resolution_clock::duration> newTime = high_resolution_clock::now();

    if (_firstTick) _firstTick = false;
    else deltaTime = static_cast<float>((newTime - _previous).count());
    _previous = newTime;
}

float logic::Stopwatch::getDeltaTime() const noexcept{
    return deltaTime;
}
