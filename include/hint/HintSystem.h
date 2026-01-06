#ifndef HANGMAN_HINTSYSTEM_H
#define HANGMAN_HINTSYSTEM_H

#include "word/Word.h"
#include <string>
#include <vector>

// Hint system for providing assistance during gameplay
// Maximum hints per game: 3 (configurable, see README.md)
// Hints can be enabled/disabled in game settings
// See README.md for hint system specifications
class HintSystem {
private:
    std::vector<std::string> hints;
    int currentHintIndex;
    int maxHints;  // Default: 3 hints per game (see README.md)
    bool hintsEnabled;
    
public:
    HintSystem();
    ~HintSystem() = default;
    
    void generateHints(const Word& word);
    std::string getNextHint();
    bool hasMoreHints() const;
    
    void setMaxHints(int max) { maxHints = max; }  // Default: 3 (see README.md)
    void setHintsEnabled(bool enabled) { hintsEnabled = enabled; }
    bool getHintsEnabled() const { return hintsEnabled; }
    
    void reset();
    
    // TODO: Implement hint generation algorithm
    // TODO: Add hint categories (definition, synonym, etc.)
};

#endif // HANGMAN_HINTSYSTEM_H

