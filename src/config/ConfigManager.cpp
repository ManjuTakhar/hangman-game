#include "config/ConfigManager.h"
#include "utils/Logger.h"
#include <fstream>
#include <sstream>
#include <algorithm>

ConfigManager::ConfigManager() : isLoaded(false) {
    setDefaultSettings();
}

void ConfigManager::setDefaultSettings() {
    settings["window_width"] = "800";
    settings["window_height"] = "600";
    settings["fullscreen"] = "false";
    settings["sound_enabled"] = "true";
    settings["music_enabled"] = "true";
    settings["difficulty"] = "medium";
    // TODO: Add more default settings
}

bool ConfigManager::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::WARNING, "Config file not found: " + filename);
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // TODO: Handle comments in config file
        // TODO: Handle empty lines
        parseLine(line);
    }
    
    file.close();
    isLoaded = true;
    Logger::log(LogLevel::INFO, "Config loaded from: " + filename);
    return true;
}

bool ConfigManager::save(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::ERROR, "Failed to open config file for writing: " + filename);
        return false;
    }
    
    for (const auto& pair : settings) {
        file << pair.first << "=" << pair.second << "\n";
    }
    
    file.close();
    return true;
}

void ConfigManager::parseLine(const std::string& line) {
    size_t pos = line.find('=');
    if (pos == std::string::npos) {
        return;
    }
    
    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    
    // TODO: Trim whitespace from key and value
    settings[key] = value;
}

std::string ConfigManager::getString(const std::string& key, const std::string& defaultValue) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return defaultValue;
}

int ConfigManager::getInt(const std::string& key, int defaultValue) const {
    std::string value = getString(key);
    if (value.empty()) {
        return defaultValue;
    }
    // TODO: Add error handling for invalid integers
    return std::stoi(value);
}

bool ConfigManager::getBool(const std::string& key, bool defaultValue) const {
    std::string value = getString(key);
    if (value.empty()) {
        return defaultValue;
    }
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);
    return value == "true" || value == "1";
}

float ConfigManager::getFloat(const std::string& key, float defaultValue) const {
    std::string value = getString(key);
    if (value.empty()) {
        return defaultValue;
    }
    // TODO: Add error handling for invalid floats
    return std::stof(value);
}

void ConfigManager::setString(const std::string& key, const std::string& value) {
    settings[key] = value;
}

void ConfigManager::setInt(const std::string& key, int value) {
    settings[key] = std::to_string(value);
}

void ConfigManager::setBool(const std::string& key, bool value) {
    settings[key] = value ? "true" : "false";
}

void ConfigManager::setFloat(const std::string& key, float value) {
    settings[key] = std::to_string(value);
}

