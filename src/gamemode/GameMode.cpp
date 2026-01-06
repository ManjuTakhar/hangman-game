#include "gamemode/GameMode.h"
#include "word/Word.h"
#include "player/Player.h"
#include "utils/Logger.h"

GameMode::GameMode() : isGameOver(false), isGameWon(false) {
}

void GameMode::checkGameOver() {
    if (!currentWord || !player) {
        return;
    }
    
    // TODO: Check if word is completely guessed
    if (currentWord->isComplete()) {
        isGameWon = true;
        isGameOver = true;
        return;
    }
    
    // TODO: Check if player has run out of lives
    if (player->getLives() <= 0) {
        isGameWon = false;
        isGameOver = true;
    }
}

void GameMode::processGuess(char letter) {
    if (!currentWord || !player) {
        return;
    }
    
    // TODO: Validate letter input
    // TODO: Check if letter was already guessed
    
    bool correct = currentWord->guessLetter(letter);
    
    if (!correct) {
        player->loseLife();
        // TODO: Update incorrect guesses list
    } else {
        // TODO: Update correct guesses display
        // TODO: Award points for correct guess
    }
    
    checkGameOver();
}

