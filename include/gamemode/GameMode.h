#ifndef HANGMAN_GAMEMODE_H
#define HANGMAN_GAMEMODE_H

#include "display/DisplayManager.h"
#include "input/InputManager.h"
#include "word/Word.h"
#include "player/Player.h"
#include <memory>

class GameMode {
protected:
    std::unique_ptr<Word> currentWord;
    std::unique_ptr<Player> player;
    bool isGameOver;
    bool isGameWon;
    
public:
    GameMode();
    virtual ~GameMode() = default;
    
    virtual bool initialize() = 0;
    virtual void cleanup() = 0;
    virtual void update() = 0;
    virtual void render(DisplayManager& display) = 0;
    virtual void handleInput(InputManager& input) = 0;
    
    bool getIsGameOver() const { return isGameOver; }
    bool getIsGameWon() const { return isGameWon; }
    
protected:
    virtual void checkGameOver();
    virtual void processGuess(char letter);
    // TODO: Add hint system integration
};

#endif // HANGMAN_GAMEMODE_H

