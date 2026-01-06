#include "word/Word.h"
#include "display/DisplayManager.h"
#include <algorithm>
#include <cctype>

Word::Word(const std::string& word) : originalWord(word) {
    std::transform(originalWord.begin(), originalWord.end(), 
                   originalWord.begin(), ::tolower);
    initializeGuessedLetters();
}

void Word::initializeGuessedLetters() {
    guessedLetters.resize(originalWord.length(), false);
    
    // TODO: Handle spaces and special characters differently
    // TODO: Auto-reveal spaces and hyphens
}

bool Word::guessLetter(char letter) {
    letter = std::tolower(letter);
    
    if (guessedChars.find(letter) != guessedChars.end()) {
        // TODO: Handle already guessed letter (maybe penalize?)
        return false;
    }
    
    guessedChars.insert(letter);
    
    bool found = false;
    for (size_t i = 0; i < originalWord.length(); ++i) {
        if (originalWord[i] == letter) {
            guessedLetters[i] = true;
            found = true;
        }
    }
    
    if (!found) {
        incorrectGuesses.insert(letter);
    }
    
    return found;
}

bool Word::isComplete() const {
    for (bool guessed : guessedLetters) {
        if (!guessed) {
            return false;
        }
    }
    return true;
}

bool Word::containsLetter(char letter) const {
    letter = std::tolower(letter);
    return originalWord.find(letter) != std::string::npos;
}

std::string Word::getDisplayString() const {
    std::string display;
    for (size_t i = 0; i < originalWord.length(); ++i) {
        if (guessedLetters[i]) {
            display += originalWord[i];
        } else {
            display += '_';
        }
        display += ' ';
    }
    return display;
}

int Word::getRemainingLetters() const {
    int count = 0;
    for (bool guessed : guessedLetters) {
        if (!guessed) {
            count++;
        }
    }
    return count;
}

void Word::render(DisplayManager& display) {
    // TODO: Implement proper word rendering with spacing
    // TODO: Add letter reveal animations
    std::string displayStr = getDisplayString();
    // display.renderText(displayStr, x, y);
}

