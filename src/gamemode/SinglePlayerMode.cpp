#include "gamemode/SinglePlayerMode.h"
#include "player/Player.h"
#include "word/Word.h"
#include "display/DisplayManager.h"
#include "input/InputManager.h"
#include "utils/Logger.h"

SinglePlayerMode::SinglePlayerMode(const ConfigManager& config) 
    : config(config), currentRound(1) {
}

bool SinglePlayerMode::initialize() {
    if (!wordList.load("data/words.txt")) {
        Logger::log(LogLevel::ERROR, "Failed to load word list");
        return false;
    }
    
    // TODO: Load difficulty settings from config
    difficulty = Difficulty::MEDIUM;
    
    player = std::make_unique<Player>("Player1");
    player->setLives(6); // Standard hangman lives
    
    loadNewWord();
    
    Logger::log(LogLevel::INFO, "Single player mode initialized");
    return true;
}

void SinglePlayerMode::cleanup() {
    currentWord.reset();
    player.reset();
    Logger::log(LogLevel::INFO, "Single player mode cleaned up");
}

void SinglePlayerMode::update() {
    if (isGameOver) {
        // TODO: Show game over screen
        // TODO: Handle restart option
        return;
    }
    
    // TODO: Update game timer
    // TODO: Update animations
}

void SinglePlayerMode::render(DisplayManager& display) {
    if (!currentWord || !player) {
        return;
    }
    
    // TODO: Render hangman drawing based on lives
    // TODO: Render word display with blanks
    // TODO: Render guessed letters
    // TODO: Render player stats (lives, score)
    
    currentWord->render(display);
    player->render(display);
}

void SinglePlayerMode::handleInput(InputManager& input) {
    if (isGameOver) {
        // TODO: Handle restart/exit input
        return;
    }
    
    // TODO: Process letter input
    // TODO: Handle hint request
    // TODO: Handle pause input
    
    char letter = input.getLastCharInput();
    if (letter >= 'a' && letter <= 'z') {
        GameMode::processGuess(letter);
    }
}

void SinglePlayerMode::loadNewWord() {
    std::string word = wordList.getRandomWord(difficulty);
    if (word.empty()) {
        Logger::log(LogLevel::ERROR, "Failed to get random word");
        return;
    }
    
    currentWord = std::make_unique<Word>(word);
    // TODO: Reset player state for new word
    // TODO: Clear previous guesses
}

void SinglePlayerMode::handleRoundComplete() {
    if (isGameWon) {
        // TODO: Award points
        // TODO: Update statistics
        currentRound++;
        loadNewWord();
    }
}

