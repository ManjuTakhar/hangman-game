#ifndef HANGMAN_LOGGER_H
#define HANGMAN_LOGGER_H

#include <string>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    static bool isInitialized;
    static std::string logFile;
    
    static std::string levelToString(LogLevel level);
    static void writeToFile(const std::string& message);
    
public:
    static void initialize(const std::string& filename = "hangman.log");
    static void shutdown();
    
    static void log(LogLevel level, const std::string& message);
    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
    
    // TODO: Add log rotation
    // TODO: Add log filtering by level
};

#endif // HANGMAN_LOGGER_H

