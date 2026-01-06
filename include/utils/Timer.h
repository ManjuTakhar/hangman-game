#ifndef HANGMAN_TIMER_H
#define HANGMAN_TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point pauseTime;
    bool isPaused;
    bool isRunning;
    
public:
    Timer();
    ~Timer() = default;
    
    void start();
    void stop();
    void pause();
    void resume();
    void reset();
    
    double getElapsedSeconds() const;
    double getElapsedMilliseconds() const;
    
    bool getIsRunning() const { return isRunning; }
    bool getIsPaused() const { return isPaused; }
    
    // TODO: Add timer callbacks
    // TODO: Add countdown timer functionality
};

#endif // HANGMAN_TIMER_H

