#ifndef HANGMAN_INPUTVALIDATOR_H
#define HANGMAN_INPUTVALIDATOR_H

#include <string>

class InputValidator {
public:
    static bool isValidLetter(char c);
    static bool isValidWord(const std::string& word);
    static bool isAlphabetic(const std::string& str);
    static std::string sanitizeInput(const std::string& input);
    
    // TODO: Add more validation functions
    // TODO: Add profanity filter
};

#endif // HANGMAN_INPUTVALIDATOR_H

