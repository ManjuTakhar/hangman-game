#include "utils/Logger.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

bool Logger::isInitialized = false;
std::string Logger::logFile = "hangman.log";

void Logger::initialize(const std::string& filename) {
    logFile = filename;
    isInitialized = true;
    info("Logger initialized");
}

void Logger::shutdown() {
    if (isInitialized) {
        info("Logger shutting down");
        isInitialized = false;
    }
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void Logger::writeToFile(const std::string& message) {
    if (!isInitialized) return;
    
    std::ofstream file(logFile, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
        file.close();
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::string timestamp = oss.str();
    
    std::string logMessage = "[" + timestamp + "] [" + levelToString(level) + "] " + message;
    
    std::cout << logMessage << std::endl;
    writeToFile(logMessage);
}

void Logger::debug(const std::string& message) {
    log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::ERROR, message);
}

