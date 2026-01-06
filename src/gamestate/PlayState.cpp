#include "gamestate/PlayState.h"
#include "gamemode/SinglePlayerMode.h"
#include "utils/Logger.h"

PlayState::PlayState(Game& game) : game(game) {
}

bool PlayState::enter() {
    // TODO: Show difficulty selection menu
    // TODO: Allow player to choose game mode
    
    gameMode = std::make_unique<SinglePlayerMode>(game.getConfig());
    if (!gameMode->initialize()) {
        Logger::log(LogLevel::ERROR, "Failed to initialize game mode");
        return false;
    }
    
    Logger::log(LogLevel::INFO, "Entered play state");
    return true;
}

void PlayState::exit() {
    if (gameMode) {
        gameMode->cleanup();
    }
    Logger::log(LogLevel::INFO, "Exited play state");
}

void PlayState::update() {
    if (gameMode) {
        gameMode->update();
        
        // TODO: Check for game over conditions
        // TODO: Handle game completion
    }
}

void PlayState::render(DisplayManager& display) {
    if (gameMode) {
        gameMode->render(display);
    }
    
    // TODO: Render HUD (score, lives, etc.)
}

void PlayState::handleInput(InputManager& input) {
    if (input.isKeyPressed(KeyCode::ESCAPE)) {
        // TODO: Show pause menu
        // TODO: Return to main menu option
    }
    
    if (gameMode) {
        gameMode->handleInput(input);
    }
}

