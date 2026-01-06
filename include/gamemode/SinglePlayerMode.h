#ifndef HANGMAN_SINGLEPLAYERMODE_H
#define HANGMAN_SINGLEPLAYERMODE_H

#include "gamemode/GameMode.h"
#include "config/ConfigManager.h"
#include "difficulty/Difficulty.h"
#include "wordlist/WordListManager.h"

class SinglePlayerMode : public GameMode {
private:
    ConfigManager config;
    Difficulty difficulty;
    WordListManager wordList;
    int currentRound;
    
    void loadNewWord();
    void handleRoundComplete();
    
public:
    SinglePlayerMode(const ConfigManager& config);
    ~SinglePlayerMode() override = default;
    
    bool initialize() override;
    void cleanup() override;
    void update() override;
    void render(DisplayManager& display) override;
    void handleInput(InputManager& input) override;
};

#endif // HANGMAN_SINGLEPLAYERMODE_H

