#ifndef HANGMAN_WORD_H
#define HANGMAN_WORD_H

#include "display/DisplayManager.h"
#include <string>
#include <vector>
#include <set>

class Word {
private:
    std::string originalWord;
    std::vector<bool> guessedLetters;
    std::set<char> guessedChars;
    std::set<char> incorrectGuesses;
    
    void initializeGuessedLetters();
    
public:
    explicit Word(const std::string& word);
    ~Word() = default;
    
    bool guessLetter(char letter);
    bool isComplete() const;
    bool containsLetter(char letter) const;
    
    std::string getDisplayString() const;
    std::string getOriginalWord() const { return originalWord; }
    int getRemainingLetters() const;
    std::set<char> getIncorrectGuesses() const { return incorrectGuesses; }
    
    void render(DisplayManager& display);
    
    // TODO: Add word hint functionality
    // TODO: Add word category/theme
};

#endif // HANGMAN_WORD_H

