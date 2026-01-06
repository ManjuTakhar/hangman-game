#ifndef HANGMAN_SAVEMANAGER_H
#define HANGMAN_SAVEMANAGER_H

#include <string>

// Save file structure (JSON format stored in data/ directory)
// See README.md for save/load functionality specifications
// Required fields:
// - player_name: Name of the player
// - current_word: The word being guessed (partially revealed state)
// - guessed_letters: All letters guessed so far (correct and incorrect)
// - remaining_attempts: Number of lives/attempts remaining
// - difficulty_level: Current difficulty (easy/medium/hard/expert)
// - game_statistics: Player statistics
struct SaveData {
    std::string playerName;      // Required: Player name (see README.md)
    int currentScore;
    int lives;                   // Required: Remaining lives/attempts (see README.md)
    std::string currentWord;     // Required: Current word state (see README.md)
    std::string guessedLetters;  // Required: All guessed letters (see README.md)
    // TODO: Add more save data fields (difficulty_level, game_statistics)
};

// Manages game save/load functionality
// Save files are stored in JSON format in the data/ directory
// See README.md for detailed save file structure requirements
class SaveManager {
private:
    std::string saveDirectory;  // Default: data/ directory (see README.md)
    
public:
    SaveManager();
    ~SaveManager() = default;
    
    bool saveGame(const SaveData& data, const std::string& slot);
    bool loadGame(SaveData& data, const std::string& slot);
    bool deleteSave(const std::string& slot);
    bool saveExists(const std::string& slot) const;
    
    std::vector<std::string> getSaveSlots() const;
    
    // TODO: Add auto-save functionality
    // TODO: Add save slot management
};

#endif // HANGMAN_SAVEMANAGER_H

