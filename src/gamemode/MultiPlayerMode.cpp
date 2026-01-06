#include "gamemode/MultiPlayerMode.h"
#include "word/Word.h"
#include "player/Player.h"
#include "display/DisplayManager.h"
#include "input/InputManager.h"
#include "utils/Logger.h"
#include <vector>
#include <memory>

MultiPlayerMode::MultiPlayerMode() : currentPlayerIndex(0) {
}

bool MultiPlayerMode::initialize() {
    // TODO: Get number of players from input
    // TODO: Get player names
    // TODO: Get word from current player
    
    int numPlayers = 2; // Default
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(std::make_unique<Player>("Player" + std::to_string(i + 1)));
    }
    
    if (!players.empty()) {
        // TODO: Set current player properly
    }
    
    // TODO: Initialize word from player input
    // currentWord = std::make_unique<Word>(playerInputWord);
    
    Logger::log(LogLevel::INFO, "Multiplayer mode initialized");
    return true;
}

void MultiPlayerMode::cleanup() {
    players.clear();
    currentWord.reset();
    Logger::log(LogLevel::INFO, "Multiplayer mode cleaned up");
}

void MultiPlayerMode::update() {
    if (isGameOver) {
        // TODO: Show winner
        return;
    }
    
    handlePlayerTurn();
}

void MultiPlayerMode::render(DisplayManager& display) {
    if (!currentWord) {
        return;
    }
    
    // TODO: Render current player indicator
    // TODO: Render all players' scores
    // TODO: Render word display
    // TODO: Render hangman drawing
    
    currentWord->render(display);
    
    for (const auto& player : players) {
        player->render(display);
    }
}

void MultiPlayerMode::handleInput(InputManager& input) {
    if (isGameOver) {
        // TODO: Handle restart/exit
        return;
    }
    
    // TODO: Process input only for current player
    char letter = input.getLastCharInput();
    if (letter >= 'a' && letter <= 'z') {
        GameMode::processGuess(letter);
        switchPlayer();
    }
}

void MultiPlayerMode::switchPlayer() {
    if (players.empty()) return;
    
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    // TODO: Set current player from players vector
    // TODO: Update display for player switch
}

void MultiPlayerMode::handlePlayerTurn() {
    // TODO: Implement turn timer
    // TODO: Handle turn timeout
}

