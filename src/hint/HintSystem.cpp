#include "hint/HintSystem.h"
#include "word/Word.h"
#include "utils/Logger.h"
#include <string>

HintSystem::HintSystem() 
    : currentHintIndex(0), maxHints(3), hintsEnabled(true) {
}

void HintSystem::generateHints(const Word& word) {
    hints.clear();
    currentHintIndex = 0;
    
    std::string wordStr = word.getOriginalWord();
    
    // TODO: Generate hints based on word
    // TODO: Fetch hints from dictionary API or database
    // TODO: Create contextual hints
    
    hints.push_back("The word has " + std::to_string(wordStr.length()) + " letters");
    // TODO: Add more hint generation logic
}

std::string HintSystem::getNextHint() {
    if (!hintsEnabled || currentHintIndex >= hints.size()) {
        return "";
    }
    
    if (currentHintIndex >= maxHints) {
        return "No more hints available";
    }
    
    return hints[currentHintIndex++];
}

bool HintSystem::hasMoreHints() const {
    return currentHintIndex < hints.size() && currentHintIndex < maxHints;
}

void HintSystem::reset() {
    hints.clear();
    currentHintIndex = 0;
}

