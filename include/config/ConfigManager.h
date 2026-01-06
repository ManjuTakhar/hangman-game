#ifndef HANGMAN_CONFIGMANAGER_H
#define HANGMAN_CONFIGMANAGER_H

#include <string>
#include <map>

class ConfigManager {
private:
    std::map<std::string, std::string> settings;
    bool isLoaded;
    
    void setDefaultSettings();
    void parseLine(const std::string& line);
    
public:
    ConfigManager();
    ~ConfigManager() = default;
    
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    
    std::string getString(const std::string& key, const std::string& defaultValue = "") const;
    int getInt(const std::string& key, int defaultValue = 0) const;
    bool getBool(const std::string& key, bool defaultValue = false) const;
    float getFloat(const std::string& key, float defaultValue = 0.0f) const;
    
    void setString(const std::string& key, const std::string& value);
    void setInt(const std::string& key, int value);
    void setBool(const std::string& key, bool value);
    void setFloat(const std::string& key, float value);
    
    // TODO: Add config validation
    // TODO: Add config schema
};

#endif // HANGMAN_CONFIGMANAGER_H

