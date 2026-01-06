#include "wordlist/WordListManager.h"
#include "utils/Logger.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

WordListManager::WordListManager() : isLoaded(false) {
}

bool WordListManager::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::ERROR, "Failed to open word list file: " + filename);
        return false;
    }
    
    std::string word;
    while (std::getline(file, word)) {
        // TODO: Trim whitespace from words
        // TODO: Validate word format
        if (!word.empty()) {
            categorizeWord(word);
        }
    }
    
    file.close();
    isLoaded = true;
    Logger::log(LogLevel::INFO, "Word list loaded successfully");
    return true;
}

bool WordListManager::save(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        Logger::log(LogLevel::ERROR, "Failed to open file for writing: " + filename);
        return false;
    }
    
    // TODO: Save all words to file
    // TODO: Preserve word categorization
    
    file.close();
    return true;
}

void WordListManager::categorizeWord(const std::string& word) {
    Difficulty diff = determineDifficulty(word);
    wordLists[diff].push_back(word);
}

Difficulty WordListManager::determineDifficulty(const std::string& word) const {
    size_t length = word.length();
    
    // TODO: Implement better difficulty determination
    // TODO: Consider word frequency, complexity
    if (length <= 4) {
        return Difficulty::EASY;
    } else if (length <= 7) {
        return Difficulty::MEDIUM;
    } else {
        return Difficulty::HARD;
    }
}

std::string WordListManager::getRandomWord(Difficulty difficulty) const {
    const auto& words = wordLists.find(difficulty);
    if (words == wordLists.end() || words->second.empty()) {
        Logger::log(LogLevel::WARNING, "No words available for difficulty");
        return "";
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, words->second.size() - 1);
    
    return words->second[dis(gen)];
}

std::vector<std::string> WordListManager::getWordsByDifficulty(Difficulty difficulty) const {
    const auto& words = wordLists.find(difficulty);
    if (words == wordLists.end()) {
        return {};
    }
    return words->second;
}

void WordListManager::addWord(const std::string& word, Difficulty difficulty) {
    // TODO: Check for duplicates
    wordLists[difficulty].push_back(word);
}

void WordListManager::removeWord(const std::string& word) {
    // TODO: Remove word from all difficulty categories
    for (auto& pair : wordLists) {
        auto& words = pair.second;
        words.erase(std::remove(words.begin(), words.end(), word), words.end());
    }
}

size_t WordListManager::getWordCount(Difficulty difficulty) const {
    const auto& words = wordLists.find(difficulty);
    if (words == wordLists.end()) {
        return 0;
    }
    return words->second.size();
}

size_t WordListManager::getTotalWordCount() const {
    size_t total = 0;
    for (const auto& pair : wordLists) {
        total += pair.second.size();
    }
    return total;
}

