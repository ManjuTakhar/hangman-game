#include "validator/InputValidator.h"
#include <cctype>
#include <algorithm>

// Validates if a character is a valid letter (a-z, A-Z)
// See README.md for word validation rules
bool InputValidator::isValidLetter(char c) {
    return std::isalpha(c) != 0;
}

// Validates if a word meets game requirements:
// - Minimum length: 2 characters (see README.md)
// - Maximum length: 20 characters (see README.md)
// - Must contain only letters, spaces, or hyphens
// - Case-insensitive (automatically converted to lowercase)
bool InputValidator::isValidWord(const std::string& word) {
    if (word.empty() || word.length() < 2) {
        return false;
    }
    
    // Maximum word length: 20 characters (as specified in README.md)
    if (word.length() > 20) {
        return false;
    }
    
    // Validate word format: only letters, spaces, and hyphens allowed
    // Numbers and special characters are rejected (see README.md word validation rules)
    return isAlphabetic(word);
}

// Checks if string contains only alphabetic characters, spaces, or hyphens
// This matches the word validation rules in README.md:
// - Letters (a-z, A-Z) are allowed
// - Spaces are allowed (for multi-word phrases)
// - Hyphens are allowed (for compound words)
bool InputValidator::isAlphabetic(const std::string& str) {
    return std::all_of(str.begin(), str.end(), 
                       [](char c) { return std::isalpha(c) || c == ' ' || c == '-'; });
}

// Sanitizes user input by converting to lowercase
// All game input is case-insensitive as per README.md word validation rules
std::string InputValidator::sanitizeInput(const std::string& input) {
    std::string sanitized = input;
    
    // Convert to lowercase (case-insensitive gameplay per README.md)
    std::transform(sanitized.begin(), sanitized.end(), 
                   sanitized.begin(), ::tolower);
    
    return sanitized;
}

