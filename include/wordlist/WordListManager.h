#ifndef HANGMAN_WORDLISTMANAGER_H
#define HANGMAN_WORDLISTMANAGER_H

#include "difficulty/Difficulty.h"
#include <string>
#include <vector>
#include <map>

class WordListManager {
private:
    std::map<Difficulty, std::vector<std::string>> wordLists;
    bool isLoaded;
    
    void categorizeWord(const std::string& word);
    Difficulty determineDifficulty(const std::string& word) const;
    
public:
    WordListManager();
    ~WordListManager() = default;
    
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    
    std::string getRandomWord(Difficulty difficulty) const;
    std::vector<std::string> getWordsByDifficulty(Difficulty difficulty) const;
    
    void addWord(const std::string& word, Difficulty difficulty);
    void removeWord(const std::string& word);
    
    size_t getWordCount(Difficulty difficulty) const;
    size_t getTotalWordCount() const;
    
    // TODO: Add word validation
    // TODO: Add word filtering (profanity, length limits)
};

#endif // HANGMAN_WORDLISTMANAGER_H

