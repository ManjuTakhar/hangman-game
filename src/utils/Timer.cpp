#include "utils/Timer.h"

Timer::Timer() : isPaused(false), isRunning(false) {
}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
    isRunning = true;
    isPaused = false;
}

void Timer::stop() {
    isRunning = false;
    isPaused = false;
}

void Timer::pause() {
    if (isRunning && !isPaused) {
        pauseTime = std::chrono::high_resolution_clock::now();
        isPaused = true;
    }
}

void Timer::resume() {
    if (isRunning && isPaused) {
        // TODO: Adjust start time for paused duration
        isPaused = false;
    }
}

void Timer::reset() {
    startTime = std::chrono::high_resolution_clock::now();
    isPaused = false;
    // TODO: Reset pause time
}

double Timer::getElapsedSeconds() const {
    if (!isRunning) {
        return 0.0;
    }
    
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        now - startTime).count();
    
    // TODO: Account for paused time
    return elapsed / 1000.0;
}

double Timer::getElapsedMilliseconds() const {
    return getElapsedSeconds() * 1000.0;
}

